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

global ft_list_sort

; Bubble sort on linked lists.
ft_list_sort:
        push r12
        push r13
        push r14
        push r15
        
        ; r12: list: list_t **;
        mov r12, rdi

        ; r13: cmp: int (*)(void *, void *);
        mov r13, rsi

        ; There's nothing to do if the list's length is less than two.
        ; if (*list == 0) return;
        mov rax, [r12]
        cmp rax, 0
        je .done

        ; if ((...)->next == 0) return;
        mov rax, [rax + 8]
        cmp rax, 0
        je .done

        ; True if we have swapped at least once during the previous inner loop.
        ; By default, assume that there was a swap before.
        ; r14: swapped: bool;
        mov r14, 1

.outer:
        ; If we have not swapped during the previous loop then we are done.
        cmp r14, 0
        je .done

        ; At the start of the loop, we haven't swapped.
        mov r14, 0

        ; list_t **current = list;
        mov r15, r12
.inner:

        ; Check if there are at least two elements in the list left.
        ; if ((*current)->next == 0) goto outer;
        mov rax, [r15]
        mov rax, [rax + 8]
        cmp rax, 0
        je .outer

        ; cmp((*current)->data, (*current)->next->data);
        ; (*current)->data;
        mov rdi, [r15]
        mov rdi, [rdi]
        ; (*current)->next->data;
        mov rsi, [r15]
        mov rsi, [rsi + 8]
        mov rsi, [rsi]
        ; if (cmp(...) <= 0) goto advance;
        call r13
        cmp rax, 0
        jle .advance

        ; Set the swap flag.
        mov r14, 1

        ; The swap itself
        
        ; Before: current -> a -> b -> c.
        ; After:  current -> b -> a -> c.

        ; a = *current;
        mov r8, [r15]
        ; b = (...)->next;
        mov r9, [r8 + 8]
        ; c = (...)->next;
        mov r10, [r9 + 8]

        ; *current = b;
        ; b->next = a;
        ; a->next = c;
        mov [r15], r9
        mov [r9 + 8], r8
        mov [r8 + 8], r10

        ; Fallthrough.
.advance:

        ; current = &(*current)->next;
        mov r15, [r15]
        add r15, 8

        jmp .inner
        
.done:
        pop r15
        pop r14
        pop r13
        pop r12
        ret
