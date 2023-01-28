# Makefile
# I don't know what else to write here

module_files := $(wildcard src/modules/**/*.c)

modules:
	@echo ${module_files}
	gcc -c ${module_files}