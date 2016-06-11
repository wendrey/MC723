#include <stdio.h>

// 100*1024*1024 = 
#define ADDRESS 0x6400000

volatile int* lock = (volatile int*) ADDRESS;

int main() {

	int i;
	int reads = 20;

   	for (i = 0; i < reads; i++) {
        	printf("hello world: value %d address %d\n", *lock, lock);
        	lock++;
    	}

	return 0;

}
