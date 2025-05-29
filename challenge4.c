/***************************************************
		Pontificia Universidad Javeriana
	Autor: Juan Sebastian Alvarez Rodriguez	
	Materia: Sistemas Operativos
	topico: POSIX
	Descripcion: se crean 3 hilos los cuales ejecutan la funcion compute 
	que recibe 1 argumento, la funcion usa mutex para que cada hilo empiece 
	un "trabajo" y lo termine sin sobreponer datos esperando una salida ordenada
	de trabajo n inicio, trabajo n fin 
***************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaración de variables globales
pthread_t tid[3];              // Arreglo para almacenar los IDs de los hilos
int counter = 0;               // Contador compartido
pthread_mutex_t lock;          // Mutex para proteger el acceso al contador

// Función que ejecutan los hilos
void* compute(void *arg) {
    unsigned long i = 0;

    // Sección crítica: se protege el contador con un mutex
    pthread_mutex_lock(&lock);
    counter += 1;
    printf("\nJob %d has started\n", counter);
    pthread_mutex_unlock(&lock);

    // Simulación de trabajo largo con un bucle grande
    for (i = 0; i < 0xFFFFFFFF; i++);

    // Sección crítica protegida nuevamente para imprimir mensaje final
    pthread_mutex_lock(&lock);
    printf("\nJob %d has finished\n", counter);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void) {
    int i = 0;
    int error;

    // Inicialización del mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\nMutex init failed\n");
        return 1;
    }

    // Crear 3 hilos y espera a que terminen
    while (i < 3) {
        error = pthread_create(&tid[i], NULL, &compute, NULL);
        pthread_join(tid[i], NULL);
        if (error != 0) {
            printf("\nThread can't be created: [%s]", strerror(error));
        }
        i++;
    }

    
   

    // Destruir el mutex
    pthread_mutex_destroy(&lock);

    return 0;
}

