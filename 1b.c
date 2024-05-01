#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

double pi = 0.0;
int i_global = 0;
pthread_mutex_t mutex;

int N = 5;
int NTHREADS = 3;

void *calcularpi(void * arg) {
    int i_local;

    pthread_mutex_lock(&mutex);
    i_local = i_global;
    i_global++;
    pthread_mutex_unlock(&mutex);

    double parcela;
    while(i_local < N){
        parcela = 1.0 / pow(16, i_local) * (
            4.0 / (8 * i_local + 1) -
            2.0 / (8 * i_local + 4) -
            1.0 / (8 * i_local + 5) -
            1.0 / (8 * i_local + 6)
        );
        pi += parcela;

        pthread_mutex_lock(&mutex);
        i_local = i_global;
        i_global++;
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main(int argc, char * argv[]) {
    pthread_t *tid;

    pthread_mutex_init(&mutex, NULL);

    tid = (pthread_t *) malloc(sizeof(pthread_t) * NTHREADS);
    if (tid == NULL){
        fprintf(stderr, "ERRO--malloc\n");
        return 2;
    }

    for(int i=0; i<NTHREADS; i++){
        if(pthread_create(tid+i, NULL, calcularpi, NULL)){
            fprintf(stderr, "ERRO--pthread_create\n");
            return 3;
        }
    }

    for(int i = 0; i<NTHREADS; i++){
        if(pthread_join(*(tid+i), NULL)){
            fprintf(stderr, "ERRO--pthread_join\n");
            return 2;
        }
    }

    pthread_mutex_destroy(&mutex);

    printf("%.16f\n", pi);

    return 0;
}