#include <stdio.h>
#include <omp.h>

int primo(int n) {

  int i;

  for(i = 3; i < n; i+=2)
    if (n % i == 0)
      return 0;
  
  return 1;

}
