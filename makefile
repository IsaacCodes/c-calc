# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -std=gnu17
INCLUDES := -Iutils/include -Iproject/include

# Directories
BUILD_DIR := build
INCLUDE_DIR := include
UTILS_SOURCE_DIR := utils/source
PROJECT_SOURCE_DIR := project/source

# Source, object (generated from source), and final output files
SRC := $(wildcard $(UTILS_SOURCE_DIR)/*.c) $(wildcard $(PROJECT_SOURCE_DIR)/*.c)
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)
OUT := $(BUILD_DIR)/main.out

# Build output target
all: $(OUT)

# Linking objects
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

# Compilation rules
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean target
clean: 
	rm -rf $(BUILD_DIR)

# Reserve keywords
.PHONY: all clean