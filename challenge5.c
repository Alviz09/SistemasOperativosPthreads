/***************************************************
		Pontificia Universidad Javeriana
	Autor: Juan Sebastian Alvarez Rodriguez	
	Materia: Sistemas Operativos
	topico: POSIX
	Descripcion:Se crean 3 hilos que reciben las funciones
	f1, f2, f3; las cuales reciben un argumento nulo
	se crea el thread y se espera a que termine para 
	que la frase sea imprimida en el orden correspondiente
	
**************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * f1(void * arg){
	printf(" porque soy el mejor!!");
}
void * f2(void * arg){
	printf(" de forma rapida y divertida ");
}
void * f3(void * arg){
	printf(" Estoy aprendiendo ");
}
int main() {
	pthread_t thread01, thread02, thread03;

	pthread_create(&thread01, NULL, f3, NULL);	//crear hilo
	pthread_join(thread01, NULL);	//esperar que termine 
	
	pthread_create(&thread02, NULL, f2, NULL); 	//crear hilo
	pthread_join(thread02, NULL);		//esperar que termine 
	
	pthread_create(&thread03, NULL, f1, NULL);	//crear hilo
	pthread_join(thread03, NULL);	//esperar que termine 
	
	
	printf("\n");
return 0;
}
