# void proc(union ele *up)
# up in %rdi
proc:
    movq    8(%rdi), %rax # rax = up->y or up->next
    movq    (%rax), %rdx  # undeference, so rdx = *up->next; rax is certainly up->next
    movq    (%rdx), %rdx  # undeference, so rdx = *up->next->p
    subq    8(%rax), %rdx # rdx = *(up->next->p) - up->next->y
    movq    %rdx, (%rdi)  # up->x = rdx
    ret
