section .text

global	_ft__strdup

extern _ft__strlen
extern _ft__strcpy
extern _malloc

_ft__strdup:
	push   rdi
	call   _ft__strlen
	mov    rcx, rax
	add    rcx, 0x1
	mov    rdi, rcx
	call   _malloc
	pop    rsi
	cmp    rax, 0
	je     finish
	mov    rdi, rax
	call   _ft__strcpy
finish:
	ret