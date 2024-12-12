#include <stdio.h>
#include <stdlib.h>

int* crible_naif(int n) {
	int* est_premier = malloc((n+1)*sizeof(int));
	est_premier[0]=0;
	est_premier[1]=0;
	for (int k=2; k<n+1; k++){
		est_premier[k] = 1;
	}
	for(int i = 2; i < n; i++) {
		for(int j = 2; j < i-1; j++) {
			if(i%j == 0) {
				est_premier[i] = 0;
		       		break;
			}
		}
	}
	return est_premier;
}

int main() {
	int n = 100;
	int * tab = crible_naif(n);
	for(int i = 0; i < n; i++) {
		if (tab[i]) {
			printf("Nombres premiers très naïf %i\n", i);
		}
	}
}
