.PHONY: test
test:
	nasm -f elf64 the.nasm
	cc the.o tests.c
	./a.out
