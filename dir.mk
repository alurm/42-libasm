.DEFAULT_GOAL := test

FORCE:

../libasm.a: FORCE
	cd .. && $(MAKE) libasm.a

a.out: tests.c ../libasm.a
	cc -g -O0 $^

.PHONY: test
test: a.out
	./a.out
