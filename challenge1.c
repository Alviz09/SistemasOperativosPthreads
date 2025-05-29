/***************************************************
		Pontificia Universidad Javeriana
	Autor: Juan Sebastian Alvarez Rodriguez	
	Materia: Sistemas Operativos
	topico: POSIX
	Descripcion: Se crean dos hilos los cuales ejecutan la 
	funcion print_message_function la cual recibe un argumento
	despues se usa pthread_join para esperar que el proceso termie 
	asegurando que el hilo principal no finalice antes de que 
	los hilos hijos completen su tarea.

***************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *print_message_function(void *ptr) {
    char *message = (char *) ptr;
    printf("%s \n", message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2;

    // Crear los hilos
    iret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
    iret2 = pthread_create(&thread2, NULL, print_message_function, (void*) message2);

    printf("Thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);

    // Esperar que los hilos terminen
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
