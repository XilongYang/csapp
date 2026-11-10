	.text
	.globl	find_range
	.type	find_range, @function
find_range:
    xorl     %eax, %eax
    vxorps   %xmm1, %xmm1, %xmm1
    vucomiss %xmm1, %xmm0
    movl     $-2, %ecx
    movl     $-1, %edx
    movl     $1,  %esi
    cmovb    %ecx, %eax
    cmove    %edx, %eax
    cmovp    %esi, %eax
    addl     $2, %eax
    ret
    .LFE0:
	.size	find_range, .-find_range
	.ident	"GCC: (GNU) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
