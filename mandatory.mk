.DEFAULT_GOAL := test

FORCE:

../libasm.a: FORCE
	cd .. && $(MAKE) all

a.out: tests.c reference.c ../libasm.a
	cc -g -O0 tests.c ../libasm.a

.PHONY: test
test: a.out
	./a.out
