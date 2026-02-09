# Philosophers

This project is a simulation of the classic **Dining Philosophers problem**, a standard computer science problem used to illustrate synchronization issues in concurrent algorithm design and resolving techniques.

## The Problem

* Three or more philosophers sit at a round table, each alternating between eating, thinking, and sleeping.
* Each needs two forks to eat, but there are only as many forks as philosophers.
* A philosopher needs two forks to eat, one for each hand.
* The philosophers must never starve.
* Philosophers don't know if another philosopher is about to die.


## Implementation

The project follows specific rules:
* **Threads:** Each philosopher is a thread.
* **Forks as Mutexes**: Forks are represented and synchronized using mutexes.
* **Console Output**: Printing is also synchronized to prevent garbled output.
* **Monitor Thread**: Observes and ensures philosophers do not starve.

### File Structure
* `philo.c`: Main entry point and thread creation.
* `parsing.c`: Validates arguments (integers only, positive numbers).
* `monitor.c`: Observer thread that checks for death or meal limits.
* `routine.c`: The lifecycle of a philosopher (eating, sleeping, thinking).
* `start_data.c`: Initialization of structs and time functions.
* `utils.c`: Helper functions and safe printing.

## How to Run

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]
```
- `number_of_philosophers`: How many philosophers (>= 3)
- `time_to_die`: ms before a philosopher dies without eating
- `time_to_eat`: ms it takes a philosopher to eat
- `time_to_sleep`: ms spent sleeping
- `number_of_meals` (optional): simulation ends after each philosopher eats this many times

**Example:**  
```bash
./philo 5 800 200 200 7
```
Runs 5 philosophers, each dies without eating for 800ms, eats in 200ms, sleeps 200ms, simulation ends after each eats 7 times.

## Expected Output

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
...
```
Each line: `[timestamp(ms)] [philosopher_id] [action]`