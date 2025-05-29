# Makefile for compiling and running POSIX thread challenges
# Author: Generated based on challenges by Juan Sebastian Alvarez Rodriguez
# Description: Compiles and runs 10 C programs demonstrating POSIX threads and synchronization.

CC = gcc
CFLAGS = -Wall -pthread
TARGETS = challenge1 challenge2 challenge3 challenge4 challenge5 challenge6 challenge7 challenge8 challenge9 challenge10

# Summary of Challenges:
# challenge1.c: Two threads print messages, synchronized with pthread_join.
# challenge2.c: 10 threads increment a shared counter using a mutex, final value 10.
# challenge3.c: Two threads increment a counter, pausing between 4-11 using condition variables, stops at 15.
# challenge4.c: Three threads execute ordered tasks with mutex, printing start/end messages.
# challenge5.c: Three threads print a sentence in order using pthread_join.
# challenge6.c: Two threads modify a shared sum (+1, -1) over 900M iterations, no synchronization.
# challenge7.c: One thread adds -900M to a shared sum over 900M iterations.
# challenge8.c: Two threads access a critical section with a semaphore, simulating 4s tasks.
# challenge9.c: Two threads increment/decrement a balance 10M times, semaphore ensures final balance 0.
# challenge10.c: Three threads print a sentence in order using semaphores.

all: $(TARGETS)

challenge1: challenge1.c
	$(CC) $(CFLAGS) -o challenge1 challenge1.c

challenge2: challenge2.c
	$(CC) $(CFLAGS) -o challenge2 challenge2.c

challenge3: challenge3.c
	$(CC) $(CFLAGS) -o challenge3 challenge3.c

challenge4: challenge4.c
	$(CC) $(CFLAGS) -o challenge4 challenge4.c

challenge5: challenge5.c
	$(CC) $(CFLAGS) -o challenge5 challenge5.c

challenge6: challenge6.c
	$(CC) $(CFLAGS) -o challenge6 challenge6.c

challenge7: challenge7.c
	$(CC) $(CFLAGS) -o challenge7 challenge7.c

challenge8: challenge8.c
	$(CC) $(CFLAGS) -o challenge8 challenge8.c

challenge9: challenge9.c
	$(CC) $(CFLAGS) -o challenge9 challenge9.c

challenge10: challenge10.c
	$(CC) $(CFLAGS) -o challenge10 challenge10.c

run: all
	@echo "Running all challenges..."
	@for prog in $(TARGETS); do \
		echo "\n--- Running $$prog ---"; \
		./$$prog; \
	done

clean:
	rm -f $(TARGETS)

.PHONY: all run clean
