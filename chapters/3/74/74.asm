;range_t find_range(float x)
;x in %xmm0
find_range:
  vxorps   %xmm1, %xmm1, %xmm1
  vucomiss %xmm1, %xmm0
  jp       .L1
  jb       .L2
  je       .L3           
.L1:
  setbe    %al
  movzbl   %al, %eax
  addl     $2, %eax
  ret
.L2:
  movl     $0, %eax
  ret
.L3:
  movl     $1, %eax
  ret

