/***************************************************
    Autor: Juan Sebastian Alvarez Rodriguez    
    Materia: Sistemas Operativos
    Descripción: 
    Uso de semáforos POSIX para sincronizar el acceso 
    de dos hilos a una sección crítica compartida.
**************************************************/

#include <pthread.h>     
#include <stdio.h>      
#include <stdlib.h>     
#include <semaphore.h>   

// Declaración de un semáforo global
sem_t mutex;

// Variable global compartida entre los hilos
long balance = 0;

// Función que incrementa el valor de 'balance'
void *increment(void *arg) {
    for (long i = 0; i < 10000000; i++) {
        sem_wait(&mutex);    // Espera a que el semáforo esté disponible
        balance++;           // Sección crítica: modifica variable compartida
        sem_post(&mutex);    // Libera el semáforo
    }
    pthread_exit(NULL);      // Finaliza el hilo
}

// Función que decrementa el valor de 'balance'
void *decrement(void *arg) {
    for (long j = 0; j < 10000000; j++) {
        sem_wait(&mutex);    // Espera a que el semáforo esté disponible
        balance--;           // Sección crítica: modifica variable compartida
        sem_post(&mutex);    // Libera el semáforo
    }
    pthread_exit(NULL);      // Finaliza el hilo
}

int main() {
    pthread_t thread1, thread2;  // Identificadores de los dos hilos

    // Inicializa el semáforo como binario (valor inicial = 1)
    sem_init(&mutex, 0, 1);

    // Crea los dos hilos
    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);

    // Espera a que ambos hilos terminen
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Libera los recursos del semáforo
    sem_destroy(&mutex);

    // Imprime el valor final del balance, que debería ser 0
    printf("Value of balance is: %ld\n", balance);

    return 0;
}

