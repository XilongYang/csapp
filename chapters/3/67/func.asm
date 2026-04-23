// strB process(strA s)
1 process:
2 movq %rdi, %rax      // r = 72(%rsp)
3 movq 24(%rsp), %rdx  // d = &z
4 movq (%rdx), %rdx    // d = z
5 movq 16(%rsp), %rcx  // c = y
6 movq %rcx, (%rdi)    // *r = y
7 movq 8(%rsp), %rcx   // c = x
8 movq %rcx, 8(%rdi)   // *(r + 1) = x
9 movq %rdx, 16(%rdi)  // *(r + 2) = z
10 ret 

// long eval(long x, long y, long z) x in %rdi, y in %rsi, z in %rdx
1 eval:
2 subq $104, %rsp
3 movq %rdx, 24(%rsp)
4 leaq 24(%rsp), %rax
5 movq %rdi, (%rsp)
6 movq %rsi, 8(%rsp)
7 movq %rax, 16(%rsp)
8 leaq 64(%rsp), %rdi
9 call process // rsp - 8, (rsp) = returl address
10 movq 72(%rsp), %rax
11 addq 64(%rsp), %rax
12 addq 80(%rsp), %rax
13 addq $104, %rsp
14 ret 

// Stack Frame eval pre-call
96
88
80
72
64  <- rdi
56
48
40
32
24  z
16  &z
8   y
0   x <- rsp

// Stack Frame process
96
88  z
80  x
72  y <- rdi, rax
64  
56
48
40  
32  z
24  &z
16  y
8   x 
0   return address <- rsp

// Stack Frame eval post-call
96
88  
80  z
72  x 
64  y
56  
48    
40    
32  
24  z
16  &z
8   y
0   x <- rsp
