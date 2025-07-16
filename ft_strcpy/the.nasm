section .text

global ft_strcpy

%define the_destination rdi
%define the_source rsi
%define the_index r8
%define the_char r9b

ft_strcpy:
        mov the_index, 0

.loop:
        mov the_char, byte [the_source + the_index]
        mov byte [the_destination + the_index], the_char

        cmp the_char, 0
        je .end

        inc the_index
        jmp .loop

.end:
        mov rax, the_destination
        ret
        
