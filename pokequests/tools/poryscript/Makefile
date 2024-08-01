.PHONY: all, clean

# Determine this makefile's path.
# Be sure to place this BEFORE `include` directives, if any.
THIS_FILE := $(lastword $(MAKEFILE_LIST))

all: poryscript
	cp ../../data/poryscripts/*.pory ../../data/scripts/*.pory
	./poryscript -i ../../data/scripts/*.pory -o ../../data/scripts/pory_*.inc
	@$(MAKE) -f $(THIS_FILE) clean # invoke the clean target

clean:
	cp ../../data/scripts/*.pory ../../data/poryscripts/*.pory
	rm -f ../../data/scripts/*.pory