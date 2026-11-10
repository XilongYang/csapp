# strB process(strA s)
process:
movq %rdi, %rax      # r = 72(%rsp)
movq 24(%rsp), %rdx  # d = &z
movq (%rdx), %rdx    # d = z
movq 16(%rsp), %rcx  # c = y
movq %rcx, (%rdi)    # *r = y
movq 8(%rsp), %rcx   # c = x
movq %rcx, 8(%rdi)   # *(r + 1) = x
movq %rdx, 16(%rdi)  # *(r + 2) = z
ret

# long eval(long x, long y, long z) x in %rdi, y in %rsi, z in %rdx
eval:
subq $104, %rsp
movq %rdx, 24(%rsp)
leaq 24(%rsp), %rax
movq %rdi, (%rsp)
movq %rsi, 8(%rsp)
movq %rax, 16(%rsp)
leaq 64(%rsp), %rdi
call process # rsp - 8, (rsp) = returl address
movq 72(%rsp), %rax
addq 64(%rsp), %rax
addq 80(%rsp), %rax
addq $104, %rsp
ret

# Stack Frame eval pre-call
# 96
# 88
# 80
# 72
# 64  <- rdi
# 56
# 48
# 40
# 32
# 24  z
# 16  &z
# 8   y
# 0   x <- rsp

# Stack Frame process
# 96
# 88  z
# 80  x
# 72  y <- rdi, rax
# 64
# 56
# 48
# 40
# 32  z
# 24  &z
# 16  y
# 8   x
# 0   return address <- rsp

# Stack Frame eval post-call
# 96
# 88
# 80  z
# 72  x
# 64  y
# 56
# 48
# 40
# 32
# 24  z
# 16  &z
# 8   y
# 0   x <- rsp
