# range_t find_range(float x)
# x in %xmm0
find_range:
  vxorps   %xmm1, %xmm1, %xmm1        # Set %xmm1 = 0
  vucomiss %xmm0, %xmm1               # Compare 0:x
  ja       .L5                        # If >, goto neg
  vucomiss %xmm1, %xmm0               # Compare x:0
  jp       .L8                        # If NaN, goto posornan
  movl     $1, %eax                   # result = ZERO
  je       .L3                        # If =, goto done
.L8:                                  # posornan:
  vucomiss .LC0(%rip), %xmm0          # Compare x:0
  setbe    %al                        # Set result = NaN ? 1 : 0
  movzbl   %al, %eax                  # Zero-extend
  addl     $2, %eax                   # result += 2 (POS for > 0, OTHER for NaN)
  ret                                 # Return
.L5:                                  # neg:
  movl     $0, %eax                   # result = NEG
.L3:                                  # done:
  rep; ret                            # Return

