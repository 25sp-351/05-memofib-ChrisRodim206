CC = gcc
CFLAGS = -Wall -O2
TARGET = fibonacci_cache
SRC = MemoFib.c fibonacci.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
