# Philosophers

This project is a simulation of the classic **Dining Philosophers problem**, a standard computer science problem used to illustrate synchronization issues in concurrent algorithm design and resolving techniques.

## The Problem

Three or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table. The philosophers alternatively eat, think, or sleep.

* There are as many forks as there are philosophers.
* A philosopher needs two forks to eat, one for each hand.
* The philosophers must never starve.
* Philosophers don't know if another philosopher is about to die.


## Implementation

The project follows specific rules:
* **Threads:** Each philosopher is a thread.
* **Synchronization:** Mutexes are used to manage fork access and console printing to avoid data races.
* **Monitoring:** A separate monitor thread checks if any philosopher has died or if all have eaten enough.

### File Structure
* `philo.c`: Main entry point and thread creation.
* `parsing.c`: Validates arguments (integers only, positive numbers).
* `monitor.c`: Observer thread that checks for death or meal limits.
* `routine.c`: The lifecycle of a philosopher (eating, sleeping, thinking).
* `start_data.c`: Initialization of structs and time functions.
* `utils.c`: Helper functions and safe printing.

## How to Run

./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]

make