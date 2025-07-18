section .text

global ft_atoi_base
global ft_atoi_base_value_of_digit

value_of_digit:
ft_atoi_base_value_of_digit:
        cmp dil, '0'
        jl .hex_big

        cmp dil, '9'
        jg .hex_big

        movzx eax, dil
        sub eax, '0'
        ret

.hex_big:
        cmp dil, 'A'
        jl .hex_small
        cmp dil, 'F'
        jg .hex_small

        movzx eax, dil
        sub eax, 'A'
        add eax, 10
        ret

.hex_small:
        cmp dil, 'a'
        jl .bad
        cmp dil, 'f'
        jg .bad

        movzx eax, dil
        sub eax, 'a'
        add eax, 10
        ret

.bad:
        mov eax, 16
        ret

%define the_result r8d
%define the_index r9
%define the_string r10
%define the_base esi
%define the_current r11b

ft_atoi_base:
        ; Because value_of_digit will use rdi.
        ; esi is not touched by value_of_digit, so it's not moved.
        mov the_string, rdi
        mov the_index, 0
        mov the_result, 0

        cmp the_base, 2
        jl .bad
        cmp the_base, 16
        jg .bad

        ; Check for '-'.
        mov the_current, byte [the_string]
        cmp the_current, '-'
        jne .loop
        inc the_index

.loop:
        mov dil, byte [the_string + the_index]
        call value_of_digit
        cmp eax, the_base
        jge .maybe_negate

        imul the_result, the_base
        add the_result, eax

        inc the_index
        jmp .loop

.maybe_negate:
        mov the_current, byte [the_string]
        cmp the_current, '-'
        jne .done

        neg the_result

.done:
        mov eax, the_result
        ret

.bad:
        mov eax, 0
        ret
