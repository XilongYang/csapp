loop:
  movl  %esi, %ecx // n -> ecx
  movl  $1, %edx   // 1 -> edx
  movl  $0, %eax   // 0 -> eax
  jmp   .L2
 .L3:
  movq  %rdi, %r8  // x -> %r8
  andq  %rdx, %r8  // x & rdx -> %r8
  orq   %r8, %rax  // (x & x) | rax -> rax
  salq  %cl, %rdx  // rdx = rdx << n (low 8 bit)
 .L2:
  testq %rdx, %rdx // rdx != 0 then L3 else return
  jne   .L3
  rep; ret

%rdi: x
%esi: n

