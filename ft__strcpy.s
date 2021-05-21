section .text
	
global _ft__strcpy

_ft__strcpy:
	push    rdi
cycle:
	mov     rax, rsi
	mov		rcx, rax
	add		rcx, 0x1
	mov		rsi, rcx
	mov     dl, byte [rax]
	mov     rax, rdi
	mov		rcx, rax
	add		rcx, 0x1
	mov		rdi, rcx
	mov     byte [rax], dl
	cmp     dl, 0
	je      cycle_end
	jmp     cycle
cycle_end:	
	pop     rax
	ret