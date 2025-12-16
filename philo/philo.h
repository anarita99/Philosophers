/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:12:07 by adores            #+#    #+#             */
/*   Updated: 2025/12/14 18:43:30 by adores           ###   ########.fr       */
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
	int		philo_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long	nb_of_meals;
	bool	full;
	long	last_meal_time; //horas do ultimo meal
	pthread_t	thread_id; //philo is a thread
	t_data	*data;
}	t_philo;

typedef struct s_data
{
	long	n_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	limit_meals;
	long	start_simulation;
	bool	end_simulation; // a philo dies or all philos full
	pthread_mutex_t	*forks;
	t_philo	*philos;
}t_data;

void set_values(t_data *data, int ac, char **av);


/*
FORK = MUTEX
./philo 8 800 200 200 [5] max numero de refeiçoes
     philo n, time t die, time to eat, time to sleep
*/
