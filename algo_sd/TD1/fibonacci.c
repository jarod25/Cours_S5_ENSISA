#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibonacci_trivial(int n){
	return (n == 0 || n == 1) ? 1 : fibonacci_trivial(n-1) + fibonacci_trivial(n-2);
}


int fibonacci_memo(int n, int* table) {
	if (!table[n]) table[n] = (n == 0 || n == 1) ? 1 : (fibonacci_memo(n-1, table) + fibonacci_memo(n-2, table));
	return table[n];
}

void main() {
	int n = 49;
	int* table = malloc(n*sizeof(long double));
	clock_t fibt_start = clock();
	printf("%ld\n", fibonacci_trivial(n));
	clock_t fibt_end = clock();
	printf("Temps pour faire les %i iterations : %f secondes\n", n, ((double)(fibt_end - fibt_start))/CLOCKS_PER_SEC);
	clock_t fibm_start = clock();
	printf("%ld\n", fibonacci_memo(n, table));
	clock_t fibm_end = clock();
	printf("Temps pour faire les %i iterations : %f secondes\n", n, ((double)(fibm_end - fibm_start))/CLOCKS_PER_SEC);
}
