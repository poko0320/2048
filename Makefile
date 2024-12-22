# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

# Directories
SRC_DIR = src
INC_DIR = include
TEST_DIR = testfile

# Source Files
SRC_FILES = $(SRC_DIR)/end_screen.c $(SRC_DIR)/game.c $(SRC_DIR)/lobby.c $(SRC_DIR)/matrix.c $(SRC_DIR)/utils.c

# Test Files
TEST_FILES = $(TEST_DIR)/test_game.c $(TEST_DIR)/test_lobby.c $(TEST_DIR)/test_matrix.c $(TEST_DIR)/test_random.c

# Executable Targets
EXECUTABLES = test_game test_lobby test_matrix test_random main

# Build Rules
all: $(EXECUTABLES)

test_game: $(SRC_FILES) $(TEST_DIR)/test_game.c
	$(CC) $(CFLAGS) -o $@ $^

test_lobby: $(SRC_FILES) $(TEST_DIR)/test_lobby.c
	$(CC) $(CFLAGS) -o $@ $^

test_matrix: $(SRC_FILES) $(TEST_DIR)/test_matrix.c
	$(CC) $(CFLAGS) -o $@ $^

test_random: $(SRC_FILES) $(TEST_DIR)/test_random.c
	$(CC) $(CFLAGS) -o $@ $^

main: $(SRC_FILES) $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -o $@ $^

# Clean Rule
clean:
	rm -f $(EXECUTABLES) *.o