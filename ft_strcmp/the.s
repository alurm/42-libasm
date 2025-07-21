section .text

global ft_strcmp

%define the_s1 rdi
%define the_s2 rsi

%define the_index r8
%define the_char r10d
%define the_diff r9d

ft_strcmp:
        mov the_index, 0

.loop:
        movzx the_diff, byte [the_s1 + the_index]
        movzx the_char, byte [the_s2 + the_index]

        sub the_diff, the_char
        jne .end

        cmp the_char, 0
        je .end

        inc the_index
        jmp .loop

.end:
        mov eax, the_diff
        ret

