/***************************************************
		Pontificia Universidad Javeriana
	Autor: Juan Sebastian Alvarez Rodriguez	
	Materia: Sistemas Operativos
	topico: POSIX
	Descripcion: Se crean 10 hilos los cuales ejecutan 
	la funcion thread_function que recibe como argumento 
	el indice del hilo, despues se usa mutex para proteger 
	la variable counter, despues espera a  que los hilos 
	se sincronicen usando pthread_join e imprime el contador 
	que debe de ser 10.

***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10

// Mutex para proteger el acceso a la variable 'counter'
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// Contador compartido entre los hilos
int counter = 0;

// Función que ejecutará cada hilo
void *thread_function(void *arg) {
    int i = *(int *)arg; // Se extrae el número de hilo

    printf("Thread number: %d | Thread ID: %ld\n", i, pthread_self());	// imprime el numero del hilo y el ID del hilo usando pthread_self()

    // Sección crítica: proteger acceso al contador
    pthread_mutex_lock(&mutex1);
    counter++;
    pthread_mutex_unlock(&mutex1);

    pthread_exit(NULL); // Fin del hilo
}

int main() {
    pthread_t thread_id[NTHREADS];
    int indices[NTHREADS]; // Arreglo de índices para pasar valores únicos a cada hilo

    // Crear los hilos
    for (int i = 0; i < NTHREADS; i++) {
        indices[i] = i; // Se asigna un índice único
        //Si hay error creando el hilo se detiene el programa
        if (pthread_create(&thread_id[i], NULL, thread_function, &indices[i]) != 0) {
            perror("Error creando hilo");
            exit(EXIT_FAILURE);
        }
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < NTHREADS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    // Imprimir valor final del contador
    printf("Final counter value: %d\n", counter);

    return 0;
}

