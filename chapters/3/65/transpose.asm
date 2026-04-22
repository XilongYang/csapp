1 .L6: 
2 movq (%rdx), %rcx  // vp = *p
3 movq (%rax), %rsi  // vq = *q
4 movq %rsi, (%rdx)  // *p = vq
5 movq %rcx, (%rax)  // *q = vp
6 addq $8, %rdx      // p + 1
7 addq $120, %rax    // q + 15(120/8)
8 cmpq %rdi, %rax    // q != e -> L6
9 jne .L6 

A: A[i][j] -> %rdx
B: A[j][i] -> %rax
C: M = 15
