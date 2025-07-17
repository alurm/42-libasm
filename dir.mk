.DEFAULT_GOAL := test

include ../common.mk

a.out: tests.c the.o
	cc -g -O0 $^

.PHONY: test
test: a.out
	./a.out
