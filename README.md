# An implementation of some of libc's functions in NASM Linux x86_64

- `read`
- `write`
- `strcmp`
- `strcpy`
- `strdup`
- `strlen`
- `atoi_base` (an `atoi` which takes a base in range from 2 to 16)

# Some useful docs

- [The subject for this task at the moment of writing](en.subject.pdf)
- [x86_64 system V ABI](x86_64-abi-0.99.pdf)
- [Documentation](https://www.felixcloutier.com/x86/enter) for x86 instructions
- The NASM [documentation](https://www.nasm.us/doc/nasmdoc0.html)
- The [table](https://man7.org/linux/man-pages/man2/syscall.2.html#:~:text=to%20pass%20the%20system%20call%20arguments) with system call arguments
- System call [numbers](https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md)
- [Two's complement (Wikipedia)](https://en.wikipedia.org/wiki/Two%27s_complement)

# Testing

Either run `make test` (provided that all dependencies have been installed) or run `nix build`.
