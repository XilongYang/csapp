# double c_imag(double complex x)
c_imag:
    movapd %xmm1, %xmm0
    ret
# double c_real(double complex x)
c_real:
    rep; ret
# double complex c_sub(double complex x, double complex y)
c_sub:
    subsd %xmm2, %xmm0
    subsd %xmm3, %xmm1

# A: real:imag -> xmm<n>:xmm<n+1>
# B: xmm0:xmm1
