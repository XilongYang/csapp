;long aframe(long n, long idx, long *q)
;n in %rdi, idx in %rsi, q in %rdx
aframe:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp                    ; Allocate space for i (%rsp = s1); s1
    leaq 30(,%rdi,8), %rax            ; 30 + 8n
    andq $-16, %rax                   ; 30 + 8n round down to 16
    subq %rax, %rsp                   ; Allocate space for array p (%rsp = s2)
    leaq 15(%rsp), %r8                ; s2 + 15
    andq $-16, %r8                    ; Set %r8 to &p[0]; s2 + 15 round down to 16 -> s2 round up to 16

A. Explain, in mathematical terms, the logic in the computation of s2.
s1 - round-down-to-16(30 + 8n)

B. Explain, in mathematical terms, the logic in the computation of p.
s2 round up to 16

C. Find values of n and s1 that lead to minimum and maximum values of e1.
s1 = 64, n = 1, 30+8n=38, round down to 16 -> 32, s2 = 64-32 = 32, p = 32, e1 = 0
s1 = 65, n = 2, 30+8n=46, round down to 16 -> 32, s2 = 65-32 = 33, p = 48, e1 = 15

D. What alignment properties does this code guarantee for the values of s2
and p?
s2 is computed in a way that preserves whatever offset s1 has with the nearest multiple of 16
p is multiple of 16
