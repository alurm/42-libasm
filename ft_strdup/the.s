section .text

global ft_strdup

extern malloc
extern ft_strlen
extern ft_strcpy

%assign the_offset 0

%macro the_local 2
%assign the_offset the_offset + %2
%xdefine %1 the_offset
%endmacro

%define the_aligned_offset ((the_offset + (16 - 1)) / 16) * 16

ft_strdup:
        the_local the_len, 8
        the_local the_source, 8
        the_local the_result, 8

        enter the_aligned_offset, 0

        mov qword [rbp - the_source], rdi

        ; Call strlen.
        mov rdi, qword [rbp - the_source]
        call ft_strlen
        mov qword [rbp - the_len], rax

        ; Call malloc.
        mov rdi, qword [rbp - the_len]
        inc rdi
        call malloc
        cmp rax, 0
        je .end
        mov qword [rbp - the_result], rax

        ; Call strcpy.
        mov rdi, qword [rbp - the_result]
        mov rsi, qword [rbp - the_source]
        call ft_strcpy

        ; Write the final null byte.
        mov rdi, qword [rbp - the_result]
        mov rsi, qword [rbp - the_len]
        mov byte [rdi + rsi], 0

        mov rax, qword [rbp - the_result]

.end:
        leave
        ret
