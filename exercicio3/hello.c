#include <stdio.h>

int main () {

unsigned int a = 2147483647;
unsigned int b = 9223372036854775807;

int w = a - b;
int x = a + b;
int y = - a - b;
int z = -a + b;

printf("hello world: %d %d %d %d %d %d\n", a,b,w,x,y,z);
return 0;

}
