# POSIX Threads Challenges

**Autor:** Juan Sebastian Alvarez Rodriguez  
---

## 📘 Descripción de Retos

### ✅ challenge1.c  
- Crea dos hilos que imprimen mensajes mediante `print_message_function`.
- Usa `pthread_join` para que el hilo principal espere la finalización de los hilos secundarios.

### ✅ challenge2.c  
- Crea 10 hilos que incrementan un contador compartido.
- Usa un `mutex` para evitar condiciones de carrera.
- Imprime el número de hilo, su ID, y el valor final del contador (esperado: 10).

### ✅ challenge3.c  
- Dos hilos incrementan un contador compartido.
- El hilo `count01` se pausa entre los valores 4 y 11 usando una *variable de condición*.
- Ambos hilos terminan cuando el contador llega a 15.

### ✅ challenge4.c  
- Tres hilos ejecutan una función `compute` que simula tareas usando `sleep`.
- Un `mutex` asegura la ejecución ordenada.
- Imprime mensajes "Job N started" y "Job N finished".

### ✅ challenge5.c  
- Tres hilos imprimen partes de una frase:  
  `"Estoy aprendiendo"`, `"de forma rápida y divertida"`, `"porque soy el mejor!!"`.
- La sincronización se logra usando `pthread_join` para controlar el orden.

### ✅ challenge6.c  
- Dos hilos modifican una variable compartida (`sum`), uno sumando y el otro restando.
- Se ejecutan 900 millones de iteraciones sin sincronización.
- Se imprime el resultado final, que probablemente no será 0 por condiciones de carrera.

### ✅ challenge7.c  
- Un solo hilo modifica `sum` con un valor negativo (-900M) durante 900 millones de iteraciones.
- Imprime el resultado final.

### ✅ challenge8.c  
- Dos hilos acceden a una sección crítica simulada (4 segundos).
- Se protege con un *semáforo* para garantizar la exclusión mutua.
- Imprime mensajes al entrar y salir de la sección crítica.

### ✅ challenge9.c  
- Un hilo incrementa y otro decrementa una variable `balance` 10 millones de veces.
- Usa un semáforo para sincronización.
- El resultado esperado del balance final es **0**.

### ✅ challenge10.c  
- Tres hilos imprimen partes de una frase en orden, igual que en el reto 5.
- Esta vez, la sincronización se logra usando *semáforos POSIX*.

---
