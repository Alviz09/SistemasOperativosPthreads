/***************************************************
    Autor: Juan Sebastian Alvarez Rodriguez    
    Materia: Sistemas Operativos
    Descripción: 
    Tres hilos imprimen un mensaje en orden usando
    semáforos POSIX para sincronización.
**************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

// Semáforos para sincronizar el orden de impresión
sem_t sem_f2, sem_f1;

void *f3(void *arg) {
    printf("Estoy aprendiendo");
    sem_post(&sem_f2); // Desbloquea f2
    pthread_exit(NULL);
}

void *f2(void *arg) {
    sem_wait(&sem_f2); // Espera a que f3 termine
    printf(" de forma rapida y divertida ");
    sem_post(&sem_f1); // Desbloquea f1
    pthread_exit(NULL);
}

void *f1(void *arg) {
    sem_wait(&sem_f1); // Espera a que f2 termine
    printf(" porque soy el mejor!!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread01, thread02, thread03;

    // Inicialización de semáforos
    sem_init(&sem_f2, 0, 0);
    sem_init(&sem_f1, 0, 0);

    // Crear hilos
    pthread_create(&thread03, NULL, f3, NULL); // f3 imprime primero
    pthread_create(&thread02, NULL, f2, NULL); // f2 espera f3
    pthread_create(&thread01, NULL, f1, NULL); // f1 espera f2

    // Esperar a que todos los hilos terminen
    pthread_join(thread01, NULL);
    pthread_join(thread02, NULL);
    pthread_join(thread03, NULL);

    // Destruir semáforos
    sem_destroy(&sem_f2);
    sem_destroy(&sem_f1);

    return 0;
}

