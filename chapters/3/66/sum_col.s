# n in %rdi, A in %rsi, j in %rdx
sum_col:
leaq 1(,%rdi,4), %r8     # r8 = 4n + 1
leaq (%rdi,%rdi,2), %rax # a = 3n
movq %rax, %rdi          # d = a
testq %rax, %rax
jle .L4                  # a <= 0 -> return 0
salq $3, %r8             # r8 = (4n + 1) * 8
leaq (%rsi,%rdx,8), %rcx # c = &A[0][j]
movl $0, %eax            # a = 0
movl $0, %edx            # i = 0
.L3:
addq (%rcx), %rax        # a += *c
addq $1, %rdx            # i += 1
addq %r8, %rcx           # c += 4n + 1
cmpq %rdi, %rdx          # i != d -> Loop
jne .L3
rep; ret                 # return a
.L4:
movl $0, %eax
ret

# NR(n) = 3n
# NC(n) = 4n + 1
