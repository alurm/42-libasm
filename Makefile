.DEFAULT_GOAL := all

include common.mk

NAME := libasm.a

libasm.a: $(addprefix ft_, $(addsuffix /the.o, \
	strlen \
	strcpy \
	strcmp \
	write \
	read \
	strdup \
))
	ar r $@ $^

.PHONY: all fclean re

all: $(NAME)

fclean: clean
	rm libasm.a

re:
	$(MAKE) fclean
	$(MAKE)
