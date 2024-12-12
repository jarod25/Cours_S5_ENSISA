#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

struct ThreadData{
    int start;
    int end;
    int threadNb;
};

void* printNb(struct ThreadData* data){
    for(int i = data->start; i <= data->end; i++){
        printf("Thread %d : %d\n", data->threadNb, i);
    }
    return NULL;
}

int main(int argc, char **argv){
    if(argc != 2){
        printf("Usage: %s <nbThreads>\n", argv[0]);
        return 1;
    }
    int nbThreads = atoi(argv[1]);
    int start = 1, end = 50;
    pthread_t threads[nbThreads];
    for(int i = 1; i <= nbThreads; i++){
        struct ThreadData data = {start, end, i};
        printf("Creating thread %d\n", i);
        printf("Start: %d, End: %d\n", start, end);
        if (pthread_create(&threads[i], NULL, (void*)printNb, (void*)&data) != 0) {
            perror("pthread_create");
            return 1;
        } else {
            printf("Thread %d created\n", i);
            start += 50;
            end += 50;
        }
        sleep(1);
    }
    for(int i = 1; i < nbThreads; i++){
        pthread_join(threads[i], NULL);
    }

	return 0;
}