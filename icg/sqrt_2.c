#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[]) {
	double search = atoi(argv[1]);
	double n=1;
	double d=1;
	boucle: n=n+d;
	if(n*n > search) {
		n=n-d;
		d=d/10;
	}
	goto boucle;
}