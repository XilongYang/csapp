; i in %rdi, bp in %rsi
0000000000000000<test>:
; n = *(0x120 + bp) + *bp
; offset_last = 0x120 = 288;
; 288 - size_last < offset_a + size_a * CNT <= 288
; 284 < offset_a + size_a * CNT <= 288
0: 8b 8e 20 01 00 00  mov      0x120(%rsi), %ecx 
6: 03 0e              add      (%rsi), %ecx

; rax = 5i
; rax = bp + 8 * 5i = bp + 40i
8: 48 8d 04 bf        lea      (%rdi, %rdi, 4), %rax
c: 48 8d 04 c6        lea      (%rsi, %rax, 8), %rax
; rdx = *(bp + 40i + 8) = *(bp + size_a * i + offset_a) = &bp->a[i] = ap
; size_a = 40, offset_a = 8
; 284 < 8 + 40*CNT <= 288
; 276 < 40*CNT <= 280
; CNT = 7
10: 48 8b 50 08       mov      0x8(%rax), %rdx
14: 48 63 c9          movslq   %ecx, %rcx
; 16 + (ap - 8) + 8 * idx = ap + 8 + 8*idx = ap + size_idx + size_x*idx
; size_idx = 8, size_x = 8
; size_idx + N * size_x = 40
; N = 4
17: 48 89 4c d0 10    mov      %rcx, 0x10(%rax, %rdx, 8)
1c: c3                retq   
