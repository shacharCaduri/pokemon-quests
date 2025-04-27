#!/bin/sh

# Function to process a single file
process_file() {
    file="$1"
    dir=$(dirname "$file")
    scripts_file="$dir/scripts.inc"
    text_file="$dir/text.inc"
    
    # Initialize block flag
    txt_block=0
    
    # Read the file line by line
    while IFS= read -r line; do
        # Check if the line ends with TXT::
        case "$line" in
            *TXT::)
                txt_block=1
                echo "$line" >> "$text_file"
                ;;
            # Lines that do not start with TXT:: can be processed here
            *::*)
                txt_block=0
                echo "$line" >> "$scripts_file"
                ;;
            # Check if the line is part of the TXT:: block (starts with space or tab)
            [\ \	\v\f\#]*)
                if [ "$txt_block" -eq 1 ]; then
                    echo "$line" >> "$text_file"
                else
                    echo "$line" >> "$scripts_file"
                fi
                ;;
            # Any other line
            *)
                if [ "$txt_block" -eq 1 ]; then
                    echo "$line" >> "$scripts_file"
                else
                    echo "$line" >> "$text_file"
                fi
                ;;
        esac
    done < "$file"
}

# Function to remove consecutive empty lines
reformat_file() {
    file="$1"
    temp_file="${file}.tmp"
    awk 'NF || !blank {print; blank = !NF}' "$file" > "$temp_file" && mv "$temp_file" "$file"
}

# Main script logic
process_directory() {
    for file in "$1"/*; do
        if [ -d "$file" ]; then
            process_directory "$file"
        elif [ -f "$file" ] && [ "${file##*_pory.inc}" != "$file" ]; then
            dir=$(dirname "$file")
            scripts_file="$dir/scripts.inc"
            text_file="$dir/text.inc"
            echo " " >> "$text_file"
            echo " " >> "$scripts_file"
            echo "Processing $file..."
            process_file "$file"
            reformat_file "$text_file"
            reformat_file "$scripts_file"
        fi
    done
}

# Start processing from the root directory
process_directory "../../data/maps"
