.DEFAULT_GOAL := test

FORCE:

../bonus.a: FORCE
	cd .. && $(MAKE) bonus

a.out: tests.c reference.c ../bonus.a
	cc -g -O0 tests.c ../libasm.a

.PHONY: test
test: a.out
	./a.out
