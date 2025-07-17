.DEFAULT_GOAL := all
NAME := libasm.a

%.o: %.nasm
	nasm -f elf64 $<

functions := $(addprefix ft_, \
	strlen \
	strcpy \
	strcmp \
	write \
	read \
	strdup \
)

libasm.a: $(addsuffix /the.o, $(functions))
	ar r $@ $^

.PHONY: all fclean re test

all: $(NAME)

fclean: clean
	rm libasm.a

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: test
test:
	for function in $(functions); do \
		(cd $$function; make) || exit 1; \
	done \
	;
