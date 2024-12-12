#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void affichage1(){
	for (int i=1; i<51; i++){
		printf("%d\n",i);
	}
}

void affichage2(){
	for (int i=51; i<101; i++){
		printf("%d\n",i);
	}
}

int main(){

	pthread_t thread1;
	pthread_t thread2;
	pthread_create(&thread1,((pthread_attr_t *)NULL),(void*)affichage1,NULL);
	pthread_create(&thread2,((pthread_attr_t *)NULL),(void*)affichage2,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	int n=10;
	int out=0;
	Semaphore mutex1 = 1 ;
	Semaphore mutex2 = 1 ;


	return 0;
}