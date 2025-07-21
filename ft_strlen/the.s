section .text

global ft_strlen

%define the_string rdi
%define the_index rax
%define the_char r9b

ft_strlen:
        mov the_index, 0

.loop:
        mov the_char, byte [the_string + the_index]

        cmp the_char, 0
        je .end

        inc the_index
        jmp .loop

.end:
        ret
