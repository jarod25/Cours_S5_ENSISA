#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "utils.h"
#include "algo_tri.h"

int main (int argc, char *argv[])
{
	clock_t time_clock;
	if(argc != 2)
	{
		printf("Le programme doit avoir 1 et 1 seul argument, vous en avez mis %d !\n", (argc-1));
		return -1;
	}
	int n = atoi(argv[1]);
	srand( time( NULL ) );
	int table_non_triee[n];
	for (int i=0; i<n; i++)
	{
		table_non_triee[i] = rand();
	}
	
	printf("***** TRI PAR SÉLECTION N=%d *****\n", n);
	int* copie_non_triee = copy_table(n, table_non_triee);
	time_clock = clock();
	int* table_triee = tri_par_selection(n, copie_non_triee);
	time_clock = clock() - time_clock;
	printf("Temps de calcul: %f secondes\n", ((double)time_clock)/CLOCKS_PER_SEC);
	verification_tri(n, table_triee);
	free(table_triee);
	
	printf("***** TRI PAR INSERTION N=%d *****\n", n);
	copie_non_triee = copy_table(n, table_non_triee);
	time_clock = clock();
	table_triee = tri_par_insertion(n, copie_non_triee);
	time_clock = clock() - time_clock;
	printf("Temps de calcul: %f secondes\n", ((double)time_clock)/CLOCKS_PER_SEC);
	verification_tri(n, table_triee);
	free(table_triee);
	
	printf("***** TRI À BULLES N=%d *****\n", n);
	copie_non_triee = copy_table(n, table_non_triee);
	time_clock = clock();
	table_triee = tri_a_bulles(n, copie_non_triee);
	time_clock = clock() - time_clock;
	printf("Temps de calcul: %f secondes\n", ((double)time_clock)/CLOCKS_PER_SEC);
	verification_tri(n, table_triee);
	free(table_triee);
	
	printf("***** TRI FUSION N=%d *****\n", n);
	copie_non_triee = copy_table(n, table_non_triee);
	time_clock = clock();
	table_triee = tri_fusion(n, copie_non_triee);
	time_clock = clock() - time_clock;
	printf("Temps de calcul: %f secondes\n", ((double)time_clock)/CLOCKS_PER_SEC);
	verification_tri(n, table_triee);
	free(table_triee);
	
	printf("***** TRI RAPIDE N=%d *****\n", n);
	copie_non_triee = copy_table(n, table_non_triee);
	time_clock = clock();
	table_triee = tri_rapide(n, copie_non_triee);
	time_clock = clock() - time_clock;
	printf("Temps de calcul: %f secondes\n", ((double)time_clock)/CLOCKS_PER_SEC);
	verification_tri(n, table_triee);
	free(table_triee);
	
	printf("***** TRI PAR COMPTAGE N=%d *****\n", n);
	copie_non_triee = copy_table(n, table_non_triee);
	time_clock = clock();
	table_triee = tri_par_comptage(n, copie_non_triee);
	time_clock = clock() - time_clock;
	printf("Temps de calcul: %f secondes\n", ((double)time_clock)/CLOCKS_PER_SEC);
	verification_tri(n, table_triee);
	free(table_triee);
	
	printf("***** TRI PAR BASE N=%d *****\n", n);
	copie_non_triee = copy_table(n, table_non_triee);
	time_clock = clock();
	table_triee = tri_par_base(n, copie_non_triee);
	time_clock = clock() - time_clock;
	printf("Temps de calcul: %f secondes\n", ((double)time_clock)/CLOCKS_PER_SEC);
	verification_tri(n, table_triee);
	free(table_triee);
	
	printf("***** TRI PAR PAQUETS N=%d *****\n", n);
	copie_non_triee = copy_table(n, table_non_triee);
	time_clock = clock();
	table_triee = tri_par_paquets(n, copie_non_triee);
	time_clock = clock() - time_clock;
	printf("Temps de calcul: %f secondes\n", ((double)time_clock)/CLOCKS_PER_SEC);
	verification_tri(n, table_triee);
	free(table_triee);

}