1 typedef struct {
2   long a[2];
3   long *p;
4 } strA;
5 
6 typedef struct {
7   long u[2];
8   long q;
9 } strB;
10 
11 strB process(strA s) {
12   strB r;
13   r.u[0] = s.a[1];
14   r.u[1] = s.a[0];
15   r.q = *s.p;
16   return r;
17 }
18 
19 long eval(long x, long y, long z) {
20   strA s;
21   s.a[0] = x;
22   s.a[1] = y;
23   s.p = &z;
24   strB r = process(s);
25   return r.u[0] + r.u[1] + r.q;
26 } 

