CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = implementation
SRC = implementation.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: clean
