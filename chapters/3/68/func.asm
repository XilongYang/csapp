; p in %rdi, q in %rsi
setVal:
  movslq 8(%rsi), %rax
  addq   32(%rsi), %rax
  movq   %rax, 184(%rdi)
  ret

; Align: Any primitive object of K bytes must have a address that is a multiple of K.
; Address of int t is 8 => 4 < B <= 8;
; Address of short s[A] is 32 => 24 < 12 + 2A <= 32
; 6 < A <= 10
;
; 184 - 8 < 4AB <= 184
; 46 < AB <= 48
;
; A = 8, B = 6
