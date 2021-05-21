section .text

global _ft__list_remove_if

extern _free

_ft__list_remove_if:
	mov		r10, qword [rdi]
cycle:
	cmp		r10, 0x0
	je		cycle_end
	cmp		qword [r10], 0x0
	je		cycle_end
	call	rdx
	cmp		rax, 0x0
	jne		nexti
	mov		r11, qword [r10]
	mov		rax, qword [r11]
	mov		qword [r10], rax
	push	rdi
	mov		rdi, qword [r11 + 0x8]
	call	rcx
	pop		rdi	
	push	rdi
	mov		rdi, r11
	call	_free
	pop		rdi
nexti:
	mov		rax, qword [r11]
	mov		r11, rax
	jmp		cycle
cycle_end:
	mov		r10, rdi
	cmp		rdx, 0x0
	je		finish
	call	rdx
	cmp		rax, 0x0
	jne		finish
	mov		rax, qword [r10]
	mov		qword [rdi], rax
	push	rdi
	mov		rdi, qword [r10 + 0x8]
	call	rcx
	pop		rdi
	call	_free
finish:
	ret