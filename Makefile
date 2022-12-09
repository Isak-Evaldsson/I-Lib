# File structures
INCLUDE_DIR = ./include
SRC_DIR = src
BUILD_DIR = build

# Compiler flags
CC=gcc
CFLAGS= -g -I$(INCLUDE_DIR)
LIB_NAME = ilib

# Compile object files
FILES = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(FILES))

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	$(shell mkdir -p $(BUILD_DIR))
	$(CC) $(CFLAGS) -c $< -o $@

# Build libray
$(BUILD_DIR)/$(LIB_NAME).a: $(OBJS)
	ar rcs $@ $^

# Test
test: test/main.c $(BUILD_DIR)/$(LIB_NAME).a
	$(CC) $< $(BUILD_DIR)/$(LIB_NAME).a -o $(BUILD_DIR)/test $(CFLAGS)
	valgrind ./$(BUILD_DIR)/test

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean test rule