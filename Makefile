primo:
	gcc primo.c -o primo
	
primoO3:
	gcc primo.c -o primo -O3
	
main:
	gcc main.c calc_primo.c -o main 
	
mainO3:
	gcc main.c calc_primo.c -o main -O3


