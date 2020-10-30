#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

sem_t semaforoAB;
sem_t semaforoAC;
sem_t semaforoBA;
sem_t semaforoBC;
sem_t semaforoCA;
sem_t semaforoCB;


 void *hiloA() {
    printf ("Inicinado hiloA\n");
    printf ("Espero el Hilo B y C ....\n");
    sem_post(&semaforoAB);
    sem_post(&semaforoAC);
    sem_wait(&semaforoBA);
    sem_wait(&semaforoCA);
    printf ("Termina el hiloA.\n");
    pthread_exit(NULL);
 }
 
 void *hiloB() {
    printf ("Inicinado hiloB\n");
    printf ("Espero el Hilo A y C ....\n");
    sem_post(&semaforoBA);
    sem_post(&semaforoBC);
    sem_wait(&semaforoAB);
    sem_wait(&semaforoCB);
    printf ("Termina el hiloB.\n");
    pthread_exit(NULL);
 }
 
 void *hiloC() {
    printf ("Inicinado hiloC\n");
    printf ("Espero el Hilo A y B ....\n");
    sem_post(&semaforoCA);
    sem_post(&semaforoCB);
    sem_wait(&semaforoAC);
    sem_wait(&semaforoBC);
    printf ("Termina el hiloC.\n");
    pthread_exit(NULL);
 }
 
int main(){
    sem_init(&semaforoAB, 0 , 0);
    sem_init(&semaforoAC, 0 , 0);
    sem_init(&semaforoBA, 0 , 0);
    sem_init(&semaforoBC, 0 , 0);
    sem_init(&semaforoCA, 0 , 0);
    sem_init(&semaforoCB, 0 , 0);
    pthread_t tid[3];
    pthread_create( &tid[0], NULL , hiloA, NULL);
    pthread_create( &tid[1], NULL , hiloB, NULL);
    pthread_create( &tid[2], NULL , hiloC, NULL);
    pthread_join(tid[0] ,NULL);
    pthread_join(tid[1] ,NULL);
    pthread_join(tid[2] ,NULL);
    printf ("Terminaron todos los hilos.\n");

    return 0;
}
