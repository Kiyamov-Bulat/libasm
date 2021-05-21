section .text
	
global _ft__write
extern ___error

_ft__write:
    push    rbp
    mov     rbp, rsp
    mov     rax, 0x2000004 ; write
    syscall
    jc      error
	pop     rbp
    ret
error:
    mov     r15, rax
    call    ___error
    mov     [rax], r15
    mov     rax, -1
    pop     rbp
    ret