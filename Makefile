# Makefile
# I don't know what else to write here

CC := gcc
module_files := $(wildcard src/modules/**/*.c)
build_dir := build/

${patsubst %.c,%.o,${module_files}}: ${module_files}
	@echo ${module_files}
	@echo $@
	${CC} -c ${module_files} ${CFLAGS}

chain_test: ${module_files} tests/testModuleChain.c
	${CC} ${module_files} tests/testModuleChain.c ${CFLAGS}