/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:12:07 by adores            #+#    #+#             */
/*   Updated: 2025/09/02 16:01:09 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printd
#include <stdlib.h> //malloc
#include <unistd.h> // write, usleep
#include <sys/time.h> //gettimeofday
#include <limits.h> // INTMAX
#include <pthread.h>
#include <stdbool.h>

typedef struct s_data t_data;
typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_philo
{
	int		philo_id;
	t_fork	*left_fork;
	t_fork	*right_fork;
	long	meals_count;
	bool	full;
	long	last_meal_time;
	pthread_t	thread_id; //philo is a thread
	t_data	*data;
}	t_philo;

typedef struct s_data
{
	long	n_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	limit_meals;
	long	start_simulation;
	bool	end_simulation; // a philo dies or all philos full
	t_fork	*forks;
	t_philo	*philos;
}t_data;



/*
FORK = MUTEX
./philo 8 800 200 200 [5]
*/
