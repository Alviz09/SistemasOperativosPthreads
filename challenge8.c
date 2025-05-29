/***************************************************
    Autor: Juan Sebastian Alvarez Rodriguez    
    Materia: Sistemas Operativos
    Descripción: 
    Uso de semáforos POSIX para sincronizar el acceso 
    de dos hilos a una sección crítica.
**************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* operation(void* arg) {
    sem_wait(&mutex);           // Entra a la sección crítica
    printf("\nEntered race..\n");
    sleep(4);                   // Simula operación crítica
    sem_post(&mutex);           // Sale de la sección crítica
    printf("\nJust Exiting race...\n");
    return NULL;
}

int main() {
    sem_init(&mutex, 0, 1);     // Inicializa semáforo

    pthread_t thread01, thread02;
    pthread_create(&thread01, NULL, operation, NULL);
    sleep(2); // Retardo para observar la exclusión mutua
    pthread_create(&thread02, NULL, operation, NULL);

    pthread_join(thread01, NULL);
    pthread_join(thread02, NULL);

    sem_destroy(&mutex);        // Libera recursos
    return 0;
}

