# # Define variables for directories and files
# SRC_DIRS = ../../data/poryscripts/maps
# DST_DIRS = ../../data/maps
# WC_SRC_PORY := $(wildcard $(SRC_DIRS)/**/*.pory)
# WC_DST_PORY := $(wildcard $(DST_DIRS)/**/*.pory)
# WC_DST_DIRS := $(wildcard $(DST_DIRS)/**)
# WC_DST_PORY_INCS := $(wildcard $(DST_DIRS)/**/*_pory.inc)
# POSTFIX = _pory
# PORY_COMPILER = ../../tools/poryscript/poryscript
# FONT_CONF_PATH = ../../tools/poryscript/font_config.json

# # Default target that runs everything in sequence
# all:
# 	@$(MAKE) copyp
# 	@$(MAKE) compile
# 	@$(MAKE) cleanp
# 	@$(MAKE) update_incs

# # Clean up copied .pory files and .copied marker
# cleanp: clean_pory_files

# # Copy .pory files
# copyp: .copied

# # Rule to copy .pory files and create the .copied marker
# .copied: $(patsubst \
# 	$(SRC_DIRS)/%,\
# 	$(DST_DIRS)/%,\
# 	$(WC_SRC_PORY)\
# )
# 	@echo "All .pory files copied."
# 	@touch .copied

# # Copy individual .pory files
# $(DST_DIRS)/%: $(SRC_DIRS)/%
# 	@echo "Copying $< to $@.."
# 	@mkdir -p $(dir $@) # Ensure the target directory exists
# 	@cp $< $@

# # Generate the list of .inc files that need to be compiled
# INC_FILES := $(patsubst \
# 	$(DST_DIRS)/%.pory,\
# 	$(DST_DIRS)/%$(POSTFIX).inc,\
# 	$(WC_DST_PORY)\
# )

# # Rule to compile .pory files into .inc files
# $(DST_DIRS)/%$(POSTFIX).inc: $(DST_DIRS)/%.pory .copied
# 	@echo "Compiling $< to produce $@.."
# 	$(PORY_COMPILER) -i $< -o $@ -fc $(FONT_CONF_PATH)

# # Ensure compilation runs after the .copied file is created
# compile: $(INC_FILES)

# # Clean up copied .pory files and the .copied marker
# clean_pory_files:
# 	@echo "Clean pory files and .copied"
# 	@rm -f $(WC_DST_PORY)
# 	@rm -f .copied

# # Find all _pory.inc files in the ROOT_DIR and its subdirectories
# PORY_INC_FILES := $(shell find $(DST_DIRS) -type f -name "*_pory.inc")

# # Target to append each _pory.inc file's content to the corresponding scripts.inc or text.inc file
# append_pory_incs:
# 	./append_incs.sh

# clean_pory_incs:
# 	@rm -f $(WC_DST_PORY_INCS)

# update_incs:
# 	@$(MAKE) append_pory_incs
# 	@$(MAKE) clean_pory_incs

# .PHONY: all compile copyp cleanp clean_pory_files append_pory_incs \
# clean_pory_incs update_incs

all:
	echo "Ok .pory in maintenance"