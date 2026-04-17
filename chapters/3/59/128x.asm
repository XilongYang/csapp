store_prod:
  movq %rdx, %rax    // yl -> %rax
  cqto               // yh:yl -> %rdx:%rax 
  movq %rsi, %rcx    // xl -> %rcx
  sarq $63, %rcx     // xh -> %rcx
  imulq %rax, %rcx   // yl * xh -> %rcx
  imulq %rsi, %rdx   // xl * yh -> %rdx
  addq %rdx, %rcx    // yl * xh + xl * yh -> %rcx
  mulq %rsi          // xl * yl -> %rdx:%rax
  addq %rcx, %rdx    // 2^64 * (yl * xh + xl * yh) + xl * yl (x * y) -> %rdx:%rax
  movq %rax, (%rdi)  // (x * y) low -> dest
  movq %rdx, 8(%rdi) // (x * y) high -> dest + 8
  ret

rdi: int128_t *dest
rsi: int64_t x
rdx: int64_t y

hint: x(128 bit) = 2^64 * xh(64 bit) + xl(64 bit);
x = 2^64 * xh + xl
y = 2^64 * yh + yl
x * y = (2^64 * xh + xl) * (2^64 * yh + yl) = 2^128 * xh * yh + 2^64 * (xh * yl + xl * yh) + xl * yl
(x * y) (128 bit) = 2^64 * (xh * yl + xl * yh) + xl * yl

