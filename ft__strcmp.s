section .text
	
global _ft__strcmp

_ft__strcmp:
       push   rbp
       mov    rbp, rsp
       mov    qword [rbp - 8], rdi
       mov    qword [rbp - 16], rsi
       mov    dword [rbp - 20], 0
cycle:
       xor    eax, eax
       mov    cl, al
       mov    rdx, qword [rbp - 8]
       movsxd rsi, dword [rbp - 20]
       movsx  eax, byte [rdx + rsi]
       cmp    eax, 0
       mov    byte [rbp - 21], cl
       je     cycle_cond
       mov    rax, qword [rbp - 8]
       movsxd rcx, dword [rbp - 20]
       movsx  edx, byte [rax + rcx]
       mov    rax, qword [rbp - 16]
       movsxd rcx, dword [rbp - 20]
       movsx  esi, byte [rax + rcx]
       cmp    edx, esi
       sete   dil
       mov    byte [rbp - 21], dil
cycle_cond:
       mov    al, byte [rbp - 21]
       test   al, 1
       jne    cycle_incr
       jmp    cycle_end
cycle_incr:
       mov    eax, dword [rbp - 20]
       add    eax, 1
       mov    dword [rbp - 20], eax
       jmp    cycle
cycle_end:
       mov    rax, qword [rbp - 8]
       movsxd rcx, dword [rbp - 20]
       movsx  edx, byte [rax + rcx]
       mov    rax, qword [rbp - 16]
       movsxd rcx, dword [rbp - 20]
       movsx  esi, byte [rax + rcx]
       sub    edx, esi
       mov    eax, edx
       pop    rbp
       ret