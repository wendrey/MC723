#include <stdlib.h> 
#include <stdio.h>
#include <omp.h>
#include <math.h>

int primo(int n, int v[], int count) {

	for(int i = 0; i < count && v[i] <= sqrt(n); i ++)
	    if (n % v[i] == 0)
		    return 0;
  
return 1;

}

int main(int argc, char *argv[]) {

	int i = 2;
	int count = 1;
	int n = atoi (argv[argc-1]);
	int v[n];
	int k[n];

	if (n != 1) {

		v[0] = 2;

		for (i = 3; count < n; i += 2) {

			if (primo(i, v, count))
				v[count++] = i;
					 
		}

		i -= 2;

	}
	
	printf ("%d-ésimo primo: %d\n", n, i);

return 0;

}	
