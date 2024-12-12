#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void* helloworld(void* arg){
	printf("Hello world, je recois la valeur %d\n", *(int*)arg);
	return NULL;
}

int main(){

	pthread_t my_thread;
	int val = 5;

	pthread_create(&my_thread, NULL, helloworld, &val);
	pthread_join(my_thread,NULL);
	
	return 0;
}