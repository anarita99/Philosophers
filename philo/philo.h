/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:12:07 by adores            #+#    #+#             */
/*   Updated: 2025/12/23 14:04:34 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <unistd.h> // write, usleep
#include <sys/time.h> //gettimeofday
#include <limits.h> // INTMAX
#include <pthread.h>
#include <stdbool.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	unsigned long	philo_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	unsigned long	nb_of_meals;
	bool			full;
	unsigned long	last_meal_time; //horas do ultimo meal
	pthread_t		thread_id; //philo is a thread
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	unsigned long	n_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	limit_meals;
	unsigned long	start_simulation;
	bool			end_simulation; // a philo dies or all philos full
	pthread_mutex_t	*forks;
	pthread_mutex_t print_mutex;
	pthread_mutex_t	monitor;
	t_philo			*philos;
}	t_data;

void			set_values(t_data *data, char **av);
int				malloc_data(t_data *data);
long			char_to_num(const char *str);
void			is_eating(t_philo *philo);
void 			is_thinking(void);
void 			is_sleeping(void);
void			free_data(t_data *data);
unsigned long	get_curr_time(void);
/*
FORK = MUTEX
./philo 8 800 200 200 [5] max numero de refeiçoes
     philo n, time to die, time to eat, time to sleep
*/
