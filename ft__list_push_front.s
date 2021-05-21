section .text

global _ft__list_push_front
extern _malloc

_ft__list_push_front:
       cmp    qword [rdi], 0x0
       jne    add_elem
       push   rdi
       call   ft_create_elem
       pop    rdi
       mov    qword [rdi], rax
       jmp    finish
add_elem:
       push   rdi
       call   ft_create_elem
       pop    rdi
       cmp    rax, 0x0
       je     finish
       mov    rdx, qword [rdi]
       mov    qword [rax], rdx
       mov    qword [rdi], rax
finish:
       ret
ft_create_elem:
       push   rsi
       mov    rdi, 0x10
       call   _malloc
       pop    rsi
       cmp    rax, 0x0
       je     finish_create
       mov    qword [rax], 0x0
       mov    qword [rax + 0x8], rsi
finish_create:
       ret