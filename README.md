# Makefile for compiling and running POSIX thread challenges
# Author: Generated based on challenges by Juan Sebastian Alvarez Rodriguez
# Description: This Makefile compiles and runs 10 C programs demonstrating POSIX threads and synchronization mechanisms.
# Each challenge is compiled into an executable and can be run individually or all at once.

# Compiler and flags
CC = gcc
CFLAGS = -Wall -pthread
TARGETS = challenge1 challenge2 challenge3 challenge4 challenge5 challenge6 challenge7 challenge8 challenge9 challenge10

# Summary of Challenges:
# challenge1.c: Creates two threads that print messages using print_message_function. Uses pthread_join to ensure the main thread waits for child threads to complete.
# challenge2.c: Creates 10 threads that increment a shared counter using a mutex for synchronization. Prints thread number, ID, and final counter value (expected: 10).
# challenge3.c: Two threads increment a shared counter, with count01 pausing between counts 4-11 using a condition variable. Both threads stop at count 15.
# challenge4.c: Three threads execute the compute function, using a mutex to ensure ordered execution of simulated tasks, printing "Job N started" and "Job N finished".
# challenge5.c: Three threads print parts of a sentence ("Estoy aprendiendo", "de forma rapida y divertida", "porque soy el mejor!!") in order using pthread_join.
# challenge6.c: Two threads modify a shared variable (sum) in opposite directions (+1 and -1) over 900M iterations, without synchronization, printing the final sum.
# challenge7.c: One thread modifies a shared variable (sum) by adding a negative value (-900M) over 900M iterations, printing the final sum.
# challenge8.c: Two threads access a critical section protected by a semaphore, simulating a 4-second operation with mutual exclusion, printing entry and exit messages.
# challenge9.c: Two threads increment and decrement a shared balance variable 10M times each, using a semaphore for synchronization, expecting a final balance of 0.
# challenge10.c: Three threads print parts of a sentence in order ("Estoy aprendiendo", "de forma rapida y divertida", "porque soy el mejor!!") using semaphores for synchronization.

