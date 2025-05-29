/***************************************************
    Pontificia Universidad Javeriana
    Autor: Juan Sebastian Alvarez Rodriguez    
    Materia: Sistemas Operativos
    Tópico: POSIX Threads
    Descripción:
    Se crean 2 hilos que ejecutan una función que modifica
    una variable global `sum` en direcciones opuestas.
    Se usan argumentos por puntero para determinar la dirección
    del incremento. El programa espera a que ambos hilos terminen,
    e imprime el resultado final.
**************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_LOOPS 900000000

long long sum = 0;  // Variable global compartida entre hilos

// Función que ejecutará cada hilo
void* function(void *arg) {
    int direction = *((int*)arg); // Obtener argumento como entero
    for (int i = 0; i < NUM_LOOPS; i++) {
        sum += direction;  // Sumar o restar según el valor recibido
    }
    return NULL;
}

int main(void) {
    pthread_t thread01, thread02;

    int dir01 = 1;   // Dirección positiva
    int dir02 = -1;  // Dirección negativa

    // Crear hilos
    pthread_create(&thread01, NULL, function, &dir01);
    pthread_create(&thread02, NULL, function, &dir02);

    // Esperar a que ambos hilos terminen
    pthread_join(thread01, NULL);
    pthread_join(thread02, NULL);

    // Imprimir resultado final
    printf("Sum = %lld\n", sum);

    return 0;
}

