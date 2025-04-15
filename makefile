# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=gnu17

# Directories
SRC_DIR = source
BUILD_DIR = build
INCLUDE_DIR = include

# Source, object (generated from source), and final output files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
OUT = $(BUILD_DIR)/main

# Build output target
all: $(OUT)

# Linking objects
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation rules
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)