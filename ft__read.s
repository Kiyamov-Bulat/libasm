section .text
	
global _ft__read
extern ___error

_ft__read:
    push    rbp
    mov     rbp, rsp
    mov     rax, 0x2000003; read
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