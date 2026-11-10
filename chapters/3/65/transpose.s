.L6:
movq (%rdx), %rcx  # vp = *p
movq (%rax), %rsi  # vq = *q
movq %rsi, (%rdx)  # *p = vq
movq %rcx, (%rax)  # *q = vp
addq $8, %rdx      # p + 1
addq $120, %rax    # q + 15(120/8)
cmpq %rdi, %rax    # q != e -> L6
jne .L6

# A: A[i][j] -> %rdx
# B: A[j][i] -> %rax
# C: M = 15
