%.o: %.nasm
	nasm -f elf64 $<

.PHONY: clean
clean:
	rm -f *.o */*.o a.out */a.out
