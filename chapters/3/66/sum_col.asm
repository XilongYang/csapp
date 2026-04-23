// n in %rdi, A in %rsi, j in %rdx
1  sum_col:
2  leaq 1(,%rdi,4), %r8     // r8 = 4n + 1
3  leaq (%rdi,%rdi,2), %rax // a = 3n
4  movq %rax, %rdi          // d = a
5  testq %rax, %rax
6  jle .L4                  // a <= 0 -> return 0
7  salq $3, %r8             // r8 = (4n + 1) * 8
8  leaq (%rsi,%rdx,8), %rcx // c = &A[0][j]
9  movl $0, %eax            // a = 0
10 movl $0, %edx            // i = 0
11 .L3:
12 addq (%rcx), %rax        // a += *c
13 addq $1, %rdx            // i += 1
14 addq %r8, %rcx           // c += 4n + 1
15 cmpq %rdi, %rdx          // i != d -> Loop
16 jne .L3
17 rep; ret                 // return a
18 .L4:
19 movl $0, %eax
20 ret 

NR(n) = 3n
NC(n) = 4n + 1
