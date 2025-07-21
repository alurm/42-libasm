section .text

extern __errno_location

global ft_write

%define write_syscall_number 1

ft_write:
        mov rax, write_syscall_number
        syscall

        cmp rax, 0
        jge .ok

        neg rax
        push rax
        call __errno_location
        pop r8
        mov [rax], r8d
        mov rax, -1
        ret

.ok:
        ret

