# Define variables for directories and files
SRC_DIRS = ../../data/poryscripts/maps
DST_DIRS = ../../data/maps
WC_SRC_PORY = $(wildcard $(SRC_DIRS)/**/*.pory)
WC_DST_PORY = $(wildcard $(DST_DIRS)/**/*.pory)
PREFIX = pory_
PORY_COMPILER = ../../tools/poryscript/poryscript
FONT_CONF_PATH = ../../tools/poryscript/font_config.json

all: copy_pory_files compile

copy_pory_files: $(patsubst \
	$(SRC_DIRS)/%.pory,\
	$(DST_DIRS)/%.pory,\
	$(WC_SRC_PORY)\
)

$(DST_DIRS)/%.pory: $(SRC_DIRS)/%.pory
	@echo "Copying $< to $@.."
	@cp $< $@

clean_pory_files:
	@rm -f $(DST_DIRS)/**/*.pory

compile: $(patsubst \
	$(DST_DIRS)/%.pory,\
	$(DST_DIRS)/$(PREFIX)%.inc,\
	$(WC_DST_PORY)\
)
	
$(DST_DIRS)/$(PREFIX)%.inc: $(DST_DIR)/%.pory
	@echo "Compiling $< to $@.."
	$(PORY_COMPILER) -i $< -o $@ -fc $(FONT_CONF_PATH)

.PHONY: all clean_pory_files