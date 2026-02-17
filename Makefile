CC = gcc
CFLAGS = -Iinclude
TARGET = apc

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TARGET)
	cd tests && ./test.sh

clean:
	rm -rf build $(TARGET)

