# An implementation of some of libc's functions in NASM Linux x86_64

- `read`
- `write`
- `strcmp`
- `strcpy`
- `strdup`
- `strlen`

# Some useful links

- [The subject for this task at the moment of writing](en.subject.pdf)
- [x86_64 system V ABI](x86_64-abi-0.99.pdf)
- Documentation for x86 instructions: <https://www.felixcloutier.com/x86/enter>
- The NASM documentation: <https://www.nasm.us/doc/nasmdoc0.html>
- The table with system call arguments: <https://man7.org/linux/man-pages/man2/syscall.2.html#:~:text=to%20pass%20the%20system%20call%20arguments>
- System call numbers: <https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md>

# Testing

Either run `make test` (provided that all dependencies have been installed) or run `nix build`.
