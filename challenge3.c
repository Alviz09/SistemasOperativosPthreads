/***************************************************
		Pontificia Universidad Javeriana
	Autor: Juan Sebastian Alvarez Rodriguez	
	Materia: Sistemas Operativos
	topico: POSIX
	Descripcion: se crean dos hilos uno ejecuta la 
	funcion count01 y el otro count02 ambos estan en un for infinito, 
	despues este espera a que se sincronicen y termina el programa
	
	count01: tiene una variable condicinal pthread_cond_wait la cual
	espera a condittion_cond y a condittion_mutex para continuar la 
	ejecucion, eso sucedera si el contador esta entre 4 y 11
	si no es asi se usa un mutex para incrementar el contador y verifica 
	si llego a COUNT_DONE para salir de la funcion.
	
	count2: si cont esta fuera de rango es decir cont < 4 y cont > 11 
	activa el cont1, sino este aumenta el contador
	y verifica si se completo exitosamente.
	
***************************************************/
#include <stdio.h>      
#include <stdlib.h>     
#include <pthread.h>      


pthread_mutex_t count_mutex        = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex    = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_cond     = PTHREAD_COND_INITIALIZER;

int count = 0;


#define COUNT_DONE  15   // Valor en el que ambos hilos dejan de ejecutarse
#define COUNT_HALT1  4   // Umbral inferior del rango de pausa para el hilo 1
#define COUNT_HALT2 11   // Umbral superior del rango de pausa para el hilo 1

void* count01() {
    for (;;) {
        // Verifica si el contador está en el rango de pausa
        pthread_mutex_lock(&condition_mutex);
        while (count >= COUNT_HALT1 && count <= COUNT_HALT2) {
            // Espera hasta que el hilo 2 envíe una señal para continuar
            pthread_cond_wait(&condition_cond, &condition_mutex);
        }
        pthread_mutex_unlock(&condition_mutex);

        // Incrementa el contador con protección
        pthread_mutex_lock(&count_mutex);
        count++;
        printf("Counter value functionCount == 01 <==: %d\n", count);
        pthread_mutex_unlock(&count_mutex);

        // Termina si se alcanza el valor objetivo
        if (count >= COUNT_DONE) return NULL;

        
    }
}


void* count02() {
    for (;;) {
        // Verifica si puede desbloquear al hilo 1
        pthread_mutex_lock(&condition_mutex);
        if (count < COUNT_HALT1 || count > COUNT_HALT2) {
            pthread_cond_signal(&condition_cond); // Despierta a count01 si estaba esperando
        }
        pthread_mutex_unlock(&condition_mutex);

        // Incrementa el contador con protección
        pthread_mutex_lock(&count_mutex);
        count++;
        printf("Counter value functionCount == 02 <==: %d\n", count);
        pthread_mutex_unlock(&count_mutex);

        // Termina si se alcanza el valor objetivo
        if (count >= COUNT_DONE) return NULL;

       
    }
}


int main() {
    pthread_t thread1, thread2;

    // Crea los dos hilos
    pthread_create(&thread1, NULL, count01, NULL);
    pthread_create(&thread2, NULL, count02, NULL);

    // Espera que ambos hilos terminen
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}




