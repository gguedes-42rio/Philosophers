# Philosophers

### This project is part of 42 cursus.

This project needs understanding of threads, mutexes, process and semaphores.

## The program is a simulation

Imagine a round table, with N philosophers sit waiting to eat some spagetti.

On the table, there are also N forks, the same number of philosophers, and each fork is placed in between two philosophers.

Each philosopher needs two forks to eat, the right fork and the left fork, and it needs to eat so it dont starve.

After eating, the philosopher sleeps, after sleeping the philosopher start thinking until get two forks to eat again.

A philosopher dont know when other philosopher is about to die.

## All philosophers must avoid starving!

Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]

All values must be positive numbers

Running this starts the simulation.

It will prompt the time the simulation is running, when a philosopher is thinking/eating/sleeping, when it takes a fork and when it dies.
