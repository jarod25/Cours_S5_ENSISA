#include <stdlib.h>
#include "utils.h"

void echanger(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


int* tri_par_selection(int n, int table[])
{
	int indexMin;
	for (int i = 0; i <= n-2; i++) {
		indexMin = i;
		for (int j = i+1; j <= n-1; j++) {
			if (table[j] < table[indexMin]) indexMin = j;
		}
		echanger(&table[i], &table[indexMin]);
	}
	return table;
}

int* tri_par_insertion(int n, int table[])
{
	int j, value;
	for (int i = 0; i <= n-1; i++) {
		value = table[i];
		j = i;
		while (j>0 && table[j-1] > value) {
			table[j] = table[j-1];
			j-=1;
		}
		table[j] = value;
	}
	return table;
}

int* tri_a_bulles(int n, int table[])
{
	for (int i = n-1; i >= 1; i--) {
		for (int j = 0; j <= i-1; j++) {
			if (table[j+1] < table[j]) {
				echanger(&table[j], &table[j+1]);
			}
		}
	}
	return table;
}

int* fusion(int* gauche, int n_gauche, int* droite, int n_droite)
{
	int n = n_gauche+n_droite;
	int* resultat = malloc(n*sizeof(int));
	int g=0, d=0, i=0;
	while(g<n_gauche && d<n_droite) {
		if(gauche[g] <= droite[d]) {
			resultat[i] = gauche[g];
			g++;
		}
		else {
			resultat[i] = droite[d];
			d++;
		}
		i++;
	}
	while(i < n) {
		if(g < n_gauche) {
			resultat[i] = gauche[g];
			g++;
		}
		else {
			resultat[i] = droite[d];
			d++;
		}
		i++;
	}
	free(gauche);
	free(droite);
	return resultat;
}

int* tri_fusion(int n, int table[])
{
	if(n <=1) return table;
	int* gauche = copy_partial_table(0, n/2-1, table);
	int* droite = copy_partial_table(n/2, n-1, table);
	return fusion(tri_fusion(n/2,gauche), n/2, tri_fusion(n-n/2, droite), n-n/2);
}

int* tri_rapide(int n, int table[])
{
	if (n <= 1) return table;
	
	return table;
}

int* tri_par_comptage(int n, int table[])
{
	
	return table;
}

int* tri_par_base(int n, int table[])
{
	
	return table;
}

int* tri_par_paquets(int n, int table[])
{
	
	return table;
}
