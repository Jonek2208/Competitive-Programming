#ifndef DZIELNIKI_H
#define DZIELNIKI_H

#include <stdio.h>

long long DajN() {
  static long long N = -1;
  if (N < 0)
    scanf("%lld", &N);
  return N;
}

#endif
