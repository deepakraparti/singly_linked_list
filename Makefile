CC = gcc
CFLAGS = -Wall -Werror

# Directories 
SRC_DIR = src
EXAMPLES_DIR = examples
LIB_DIR = lib
BUILD_DIR = build
BIN_DIR = bin

# Compiler flags for linking with static library
LDFLAGS = -L$(LIB_DIR) -lsll

# Static library file
LIB_FILES = $(LIB_DIR)/libsll.a

TARGET = all

.PHONY: all clean

$(TARGET): lib app

lib: $(BUILD_DIR)/sll.o
	@mkdir -p $(LIB_DIR)
	ar -rs $(LIB_FILES) $(BUILD_DIR)/sll.o

$(BUILD_DIR)/sll.o: $(SRC_DIR)/sll.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -I $(SRC_DIR)/ $(SRC_DIR)/sll.c -o $(BUILD_DIR)/sll.o

app: $(BUILD_DIR)/app.o $(LIB_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(BUILD_DIR)/app.o -o $(BIN_DIR)/app $(LDFLAGS)

$(BUILD_DIR)/app.o:
	$(CC) $(CFLAGS) -c -I $(SRC_DIR)/ $(EXAMPLES_DIR)/app.c -o $(BUILD_DIR)/app.o

clean:
	rm -rf $(LIB_DIR) $(BIN_DIR) $(BUILD_DIR)

