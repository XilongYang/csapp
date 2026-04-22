do {
  long vp = *p;
  long vq = *q;
  *p = vq;
  *q = vp;
  p += 1;
  q += 15;
} while (q != e);
