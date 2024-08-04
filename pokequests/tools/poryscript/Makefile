# Define variables for directories and files
SRC_DIR = ../../data/poryscripts
DEST_DIR = ../../data/scripts
POY_FILES = $(wildcard $(SRC_DIR)/*.pory)
DEST_POY_FILES = $(wildcard $(DEST_DIR)/*.pory)
POY_POSTFIX = _pory
INC_FILES = $(POY_FILES:$(SRC_DIR)/%.pory=$(DEST_DIR)/%$(POY_POSTFIX).inc)

# Default target
all: copy_files process_files restore_files clean

# Copy .pory files from SRC_DIR to DEST_DIR
copy_files:
	@echo "Copying .pory files from $(SRC_DIR) to $(DEST_DIR)..."
	@cp $(SRC_DIR)/*.pory $(DEST_DIR)/

# Process .pory files with poryscript
process_files: $(INC_FILES)

$(DEST_DIR)/%$(POY_POSTFIX).inc: $(DEST_DIR)/%.pory
	@echo "Processing $<, Targets $@"
	@./poryscript -i $< -o $@ -fc tools/poryscript/font_config.json

# Clean target
clean: remove_pory_files

# Restore .pory files from DEST_DIR to SRC_DIR
restore_files:
	@echo "Restoring .pory files from $(DEST_DIR) to $(SRC_DIR)..."
	@if ls $(DEST_DIR)/*.pory 1> /dev/null 2>&1; then cp $(DEST_DIR)/*.pory $(SRC_DIR)/; fi

# Remove .pory files from DEST_DIR
remove_pory_files:
	@echo "Cleaning up .pory files from $(DEST_DIR)..."
	@rm -f $(DEST_DIR)/*.pory

# Remove all files from DEST_DIR that turned from .pory to .inc
# the files that were turned from .pory to .inc have _pory before the .inc
# and something like this: <somename>_pory.inc
clean_pory_incs:
	@echo "Cleaning up *_pory.inc files from $(DEST_DIR)..."
	@rm -f $(DEST_DIR)/*_pory.inc

# Phony targets
.PHONY: all copy_files process_files clean restore_files remove_pory_files clean_pory_incs
