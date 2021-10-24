CC = gcc
PROJECT_MANAGER = project
PRJOCET_BIN = listpost

# FLAGS
BUILD_FLAG = -lm
CFLAG = -Wall -std=c99
TEST_FLAG = -lcheck -lcheck -lm -lpthread -lrt -lsubunit -std=c99 -lsubunit -lgcov -coverage

BUILD_SRC = ./build/src
BUILD_TEST = ./build/test

BIN_SRC = $(shell find src -name "*.c")
BIN_OBJ = $(patsubst %.c,build/%.o,$(BIN_SRC))

NMAIN_SRC = $(shell find src -name "*.c"  ! -name "main_*" ! -name "main.c")
NMAIN_OBJ = $(patsubst %.c,build/%.o,$(NMAIN_SRC))

# TESTING CONFIGURATION
TESTING_FILE = $(shell find test -name "*.c")
TESTING_OBJ = $(patsubst %.c,build/%.o,$(TESTING_FILE))

# SOURCE CODE TO OBJECT FILE
./build/src/%.o: ./src/%.c ./src/%.h
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) -c $< -o $@

./build/src/%.o: ./src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) -c $< -o $@

./build/test/%.o: ./test/%.c
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) -fprofile-arcs -ftest-coverage -c $< -o $@

all: clear build

clear:
	@rm -rf build/* bin/*

./bin/test: ${TESTING_OBJ} $(NMAIN_OBJ)
	@mkdir -p bin
	@$(CC) -g $^ -o $@ $(BUILD_FLAG) $(TEST_FLAG)

./bin/mobilita: $(BIN_OBJ)
	@mkdir -p bin
	@$(CC) $^ -o $@ $(BUILD_FLAG) -O3

build: ./bin/mobilita

build_debug: $(BIN_OBJ)
	@mkdir -p bin
	@$(CC) -g $^ -o ./bin/mobilita $(BUILD_FLAG)

run: build_debug
	@./bin/mobilita

debug: build_debug

test: clean ./bin/test
	@./bin/test

clean: clear


.PHONY: test clear all adt tc clean vscode build run