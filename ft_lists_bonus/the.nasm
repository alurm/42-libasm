section .text

global ft_list_push_front

; Incorrect!
ft_list_push_front:
        mov rax, [rdi]
        mov [rsi + 8], rax
        mov [rdi], rsi
        ret

global ft_list_size

ft_list_size:
        mov eax, 0

.loop:
        cmp rdi, 0
        je .done

        inc eax
        mov rdi, [rdi + 8]
        jmp .loop

.done:
        ret

