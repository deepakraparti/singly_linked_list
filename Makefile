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
STATIC_LIB_FILE = $(LIB_DIR)/libsll.a
DYN_LIB_FILE = $(LIB_DIR)/libsll.so

TARGET = all

.PHONY: all clean

$(TARGET): static_lib dynamic_lib app

static_lib: $(BUILD_DIR)/sll.o
	@mkdir -p $(LIB_DIR)
	ar -rs $(STATIC_LIB_FILE) $(BUILD_DIR)/sll.o

$(BUILD_DIR)/sll.o: $(SRC_DIR)/sll.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -I $(SRC_DIR)/ $(SRC_DIR)/sll.c -o $(BUILD_DIR)/sll.o

dynamic_lib: $(BUILD_DIR)/d_sll.o
	$(CC) -shared -o $(DYN_LIB_FILE) $(BUILD_DIR)/d_sll.o

$(BUILD_DIR)/d_sll.o: $(SRC_DIR)/sll.c
	$(CC) -c -fPIC -I $(SRC_DIR) $(SRC_DIR)/sll.c -o $(BUILD_DIR)/d_sll.o

app: $(BUILD_DIR)/app.o $(DYN_LIB_FILE)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(BUILD_DIR)/app.o -o $(BIN_DIR)/app $(LDFLAGS)

$(BUILD_DIR)/app.o:
	$(CC) $(CFLAGS) -c -I $(SRC_DIR)/ $(EXAMPLES_DIR)/app.c -o $(BUILD_DIR)/app.o

clean:
	rm -rf $(LIB_DIR) $(BIN_DIR) $(BUILD_DIR)

