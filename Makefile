CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/game.c src/matrix.c 
TARGET = 2048.exe

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)