.DEFAULT_GOAL := all
NAME := libasm.a

%.o: %.nasm
	nasm -f elf64 $<

mandatory := $(addprefix ft_, \
	strlen \
	strcpy \
	strcmp \
	write \
	read \
	strdup \
)

bonuses := $(addsuffix _bonus, $(addprefix ft_, \
	atoi_base \
	lists \
))

mandatory.a: $(addsuffix /the.o, $(mandatory))
	ar r $@ $^

bonus.a: $(addsuffix /the.o, $(mandatory) $(bonuses))
	ar r $@ $^

.PHONY: all clean fclean re test bonus libasm.a

$(NAME) all: mandatory.a
	ln -fs $^ $(NAME)

bonus: bonus.a
	ln -fs $^ $(NAME)

clean:
	rm -f result */result a.out */a.out *.o */*.o

fclean: clean
	rm -f *.a

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: test
test:
	for function in $(mandatory) $(bonuses); do \
		(cd $$function; $(MAKE)) || exit 1; \
	done \
	;
