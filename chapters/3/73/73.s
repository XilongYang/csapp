	.text
	.globl	find_range
	.type	find_range, @function
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
    .LFE0:
	.size	find_range, .-find_range
	.ident	"GCC: (GNU) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
