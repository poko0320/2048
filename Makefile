CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/lobby.c src/game.c src/end_screen.c src/utils.c
TARGET = 2048

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)