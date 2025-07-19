section .text

extern malloc

global ft_list_push_front

ft_list_push_front:
        push rbp
        mov rbp, rsp
        sub rsp, 16

        ; Save the list and the data.
        mov [rbp - 8], rdi
        mov [rbp - 16], rsi

        ; Call malloc.
        mov rdi, 16
        call malloc

        ; Check for errors.
        cmp rax, 0
        je .bad

        ; new->data = data;
        mov rdi, [rbp - 16]
        mov [rax], rdi

        ; new->next = *list;
        mov rdi, [rbp - 8]
        mov rdi, [rdi]
        mov [rax + 8], rdi

        ; *list = new;
        mov rdi, [rbp - 8]
        mov [rdi], rax

        ; Fallthrough.
.return:
        mov rsp, rbp
        pop rbp
        ret

.bad:
        mov rdi, [rbp - 8]
        mov qword [rdi], 0
        jmp .return

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

