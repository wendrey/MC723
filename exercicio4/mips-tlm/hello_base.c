#include <stdio.h>

// 100*1024*1024 =
#define ADDRESS 0x6400000

volatile int* lock = (volatile int*) ADDRESS;

int main () {

*lock = 100;
printf("hello world: %d\n", *lock);
return 0;

}
