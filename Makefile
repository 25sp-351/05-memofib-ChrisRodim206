CC = gcc
CFLAGS = -Wall -O2
TARGET = fibonacci_cache
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
