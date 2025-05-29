/*************************************************
    Pontificia Universidad Javeriana
    Autor: Juan Sebastian Alvarez Rodriguez    
    Materia: Sistemas Operativos
    Tópico: POSIX Threads
    Descripción:
    Se crea un hilo que ejecuta una función encargada
    de modificar una variable global llamada sum.
    El valor a sumar se pasa como argumento por puntero, y puede
    ser positivo o negativo. La función realiza una gran cantidad
    de iteraciones sumando este valor a sum.

 
**************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_LOOPS 900000000  // Número de iteraciones

long long sum = 0;  // Variable global compartida

// Función que ejecutará el hilo
void* function(void *arg) {
    int valor = *(int *)arg;  // Obtener valor del argumento
    for (int i = 0; i < NUM_LOOPS; i++) {
        sum += valor;  // Sumar valor a la variable global
    }
    return NULL;  // Debe retornar un puntero
}

int main(void) {
    pthread_t id01;  // Identificador del hilo
    int dir01 = -900000000;  // Valor que será sumado 

    // Crear el hilo que ejecutará la función
    pthread_create(&id01, NULL, function, &dir01);

    // Esperar a que el hilo termine
    pthread_join(id01, NULL);

    // Imprimir el resultado final
    printf("Sum = %lld\n", sum);

    return 0;
}

