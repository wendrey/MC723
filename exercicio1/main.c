#include <stdio.h>
#include <stdlib.h> 
#include <omp.h>

int primo (int n);

int main(int argc, char *argv[]) {

  int count = 0;
  int n = atoi (argv[argc-1]);
  
  #pragma omp parallel for
  for (int i = 2; i < n; i++) {

	  if (primo(i))
		#pragma omp atomic
	 	count++;
	 
  }

	printf ("Número de primos de 0 a %d: %d\n", n, count);

return 0;

}	


