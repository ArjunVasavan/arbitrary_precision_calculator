.PHONY: all test clean

all:
	@gcc -Iinclude src/*.c -o a.out

test:
	@cd test && ./test.sh

clean:
	@rm -f a.out
