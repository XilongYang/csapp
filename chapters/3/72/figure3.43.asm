long vframe(long n, long idx, long *q)
n in %rdi, idx in %rsi, q in %rdx
Only portions of code shown

; Practice Problem 3.49
; n s1   s2:s1 - align16(22+8n) p    e1 e2
; 5 2065 22+8n = 62 -> 48; 2017 2024 1  7
; 6 2064 22+8n = 70 -> 64; 2000 2000 16 0

; 22 = 7 + 15
; Rounding down to a multiple of 16 wastes up to 15 bytes.
;   Alignment happens BEFORE the stack allocation, so the smaller the rounded value, the smaller the allocated space.
; Rounding up to a multiple of 8 wastes up to 7 bytes.
;   Alignment happens AFTER the stack allocation, so the larger the rounded value, the smaller the allocated space.

vframe:
    pushq   %rbp                    Save old %rbp
    movq    %rsp, %rbp              Set frame pointer
    subq    $16, %rsp               Allocate space for i (%rsp = s1)
    leaq    22(,%rdi,8), %rax       ;22 + 8n
    andq    $-16, %rax              ;-16:1...11110000; 22+8n round down to 16
    subq    %rax, %rsp              Allocate space for array p (%rsp = s2)
    leaq    7(%rsp), %rax           ; rsp + 7
    shrq    $3, %rax                ; rax >> 3 
    leaq    0(,%rax,8), %r8         Set %r8 to &p[0] ; r8 = rxp << 3; (rsp + 7) >>3 <<3 -> round up to 8
    movq    %r8, %rcx               Set %rcx to &p[0] (%rcx = p)
    ...

Code for initialization loop
i in %rax and on stack, n in %rdi, p in %rcx, q in %rdx

.L3:                                loop:
    movq    %rdx, (%rcx,%rax,8)     Set p[i] to q
    addq    $1, %rax                Increment i
    movq    %rax, -8(%rbp)          Store on stack
.L2:
    movq    -8(%rbp), %rax          Retrieve i from stack
    cmpq    %rdi, %rax              Compare i:n
    jl      .L3                     If <, goto loop
    ...

Code for function exit
    leave                           Restore %rbp and %rsp
    ret                             Return
