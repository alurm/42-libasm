section .text

global ft_read

extern __errno_location

%define read_syscall_number 0

ft_read:
        mov rax, read_syscall_number
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
