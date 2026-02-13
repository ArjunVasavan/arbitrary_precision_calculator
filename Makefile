.PHONY: all test clean

all:
	@gcc -Iinclude src/*.c tests/printing.c -o a.out

test:
	@gcc -Iinclude src/*.c tests/printing.c -o a.out
	@cd tests && ./test.sh

clean:
	@rm -f a.out
