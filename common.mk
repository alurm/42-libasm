.DEFAULT_GOAL := test

FORCE:

.PHONY: test
test: a.out
		./a.out

$(lib): FORCE
	cd .. && $(MAKE) $$(basename $(lib))

a.out: tests.c reference.c $(lib) $(extra_deps)
	cc -g -O0 tests.c $(lib)
