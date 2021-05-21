global _ft__strlen

section .text

_ft__strlen:
	push    rbp
	mov     rbp, rsp
    mov     qword [rbp - 8], rdi
    mov     qword [rbp - 16], rdi
cycle:
    mov     rax, qword [rbp - 8]
    cmp     byte [rax], 0
    je      cycle_end
    mov     rax, qword [rbp - 8]
    add     rax, 1
    mov     qword [rbp - 8], rax
    jmp     cycle
cycle_end:
    mov     rax, qword [rbp - 8]
    mov     rcx, qword [rbp - 16]
    sub     rax, rcx
    pop     rbp
    ret