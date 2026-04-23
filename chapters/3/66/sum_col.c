1 long sum_col(long n, long A[NR(n)][NC(n)], long j) {
2 long i;
3 long result = 0;
4 for (i = 0; i < NR(n); i++)
5 result += A[i][j];
6 return result;
7 } 
