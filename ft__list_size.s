section .text

global _ft__list_size

_ft__list_size:
	mov    rax, 0x0
cycle:
    cmp    rdi, 0x0
	je     finish
    add    eax, 0x1
    mov    dword [rbp - 0xc], eax
 	mov    rcx, rdi
    mov    rcx, qword [rcx]
    mov    rdi, rcx
    jmp    cycle
finish:
    ret    