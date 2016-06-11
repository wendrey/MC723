// Wendrey Lustosa Cardoso 148234
// MC723 - Laboratorio de Projetos de Sistemas Computacionais

#include <stdio.h>

#define SIZE	     500
#define LOCK_ADDRESS (100*1024*1024)

volatile int* lock = (volatile int*) LOCK_ADDRESS;

volatile int check1 = 0;
volatile int check2 = 0;
volatile int counter = 0;
volatile int M1[SIZE][SIZE];
volatile int M2[SIZE][SIZE];

void AcquireGlobalLock() {

	while(*lock);

}

void ReleaseGlobalLock() {

	*lock = 0;

}

void Checkpoint (int k) {

	while (check1 != k || check2 != k);

}

void sum () {

	int i, j;

	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			M1[i][j] = i+j;

}

void sub () {

    int i, j;

    for (i = 0; i < SIZE; i++)
	        for (j = 0; j < SIZE; j++)
			M2[i][j] = i-j;
							   
}

void mul1 () {

        int i, j;

        for (i = 0; i < SIZE; i++)
                for (j = 0; j < SIZE/2; j++)
                        M1[i][j] = M1[i][j] * M2[i][j];

}

void mul2 () {

        int i, j;

        for (i = 0; i < SIZE; i++)
                for (j = SIZE/2; j < SIZE; j++)
                        M1[i][j] = M1[i][j] * M2[i][j];

}

void imprime () {

	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) 
			printf("%d ", M1[i][j]);
		printf ("\n");
	}

}

void my_main () {

	// enumera os processadores
	
	int processor;

	AcquireGlobalLock();
	processor = counter++;
	printf ("hello world: processor %d\n", processor);
	ReleaseGlobalLock();

	if (processor)
		return;

	// cria duas matrizes independentes

	if (processor == 0) {
		sum();
		check1 = 1;
	}
	
	if (processor == 0) {
		sub();
		check2 = 1;
	}

	Checkpoint(1);	

	// faz operacao que envolve as duas matrizes

	if (processor == 0) {
		mul1();
		check1 = 2;
	} 
	
	if (processor == 0) {
		mul2();
		check2 = 2;
	}

	Checkpoint(2);
	
	// imprime matriz resultante
	
//	if (processor == 0) {
//		imprime();
//	}

}

int main () {

	my_main();
	return 0;

}
