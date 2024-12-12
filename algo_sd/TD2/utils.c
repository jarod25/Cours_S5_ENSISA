#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int* copy_table(int n, int table[])
{
	int* table_copie = malloc(n*sizeof(int));
	for (int i = 0; i <= n; i++)
		table_copie[i] = table[i];
	return table_copie;
}

void verification_tri(int n, int table[])
{
	bool trie = true;
	for(int i=0; i<n-1; i++) {
		if (table[i] > table[i+1]) {
			trie = false;
			break;
		}
	}
	trie ? printf("\033[01mLe tableau est bien trié\033[00m\n") : printf("\033[31mLe tableau n'est pas bien trié\033[00m\n");
}

int* copy_partial_table(int start, int end, int table[])
{

	int* table_copie = malloc((end-start+1)*sizeof(int));
	int j =0;
	for (int i = start; i <= end; i++) {
		table_copie[j] = table[i];
		j++;
	}
	return table_copie;
}
