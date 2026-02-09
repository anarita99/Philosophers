*This project has been created as part of the 42 curriculum by <adores>.*


# Philosophers

## Description

This project implements a simulation of the Dining Philosophers problem, a classical exercise in concurrent programming. The main objective is to demonstrate correct synchronization between threads to prevent deadlock and starvation, ensuring that all philosophers can eat, think, and sleep according to the rules of the problem.

## Instructions

To compile the project, run:
```bash
make
```

To execute the program, use:
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]
```
- `<number_of_philosophers>`: The total number of philosophers at the table
- `<time_to_die>`: Time in milliseconds a philosopher can live without eating
- `<time_to_eat>`: Time in milliseconds spent eating
- `<time_to_sleep>`: Time in milliseconds spent sleeping
- `[number_of_meals]`: Optional. Number of times each philosopher must eat before the simulation ends

**Example:**
```bash
./philo 5 800 200 200 3
```

## Expected Output

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
...
```
Each line: `[timestamp(ms)] [philosopher_id] [action]`

## Resources

The main resource that contributed to my understanding of this project was discussing its requirements and challenges with my colleagues.

Additional references that were helpful include:
- [Philosophers 42 Guide (Medium)](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2)
- [Dining Philosophers Problem - Video 1](https://youtu.be/zOpzGHwJ3MU?si=JY7hIxbqjZrAnBaW)
- [Dining Philosophers Problem - Video 2](https://youtu.be/raLCgPK-Igc?si=jp2iTDH8klTqtexv)
- [Dining Philosophers Problem - Video 3](https://youtu.be/xoXzp4B8aQk?si=jF9sRqrgIUCGelJp)

AI tools were used to assist with the writing and structuring of this README file.