/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:12:07 by adores            #+#    #+#             */
/*   Updated: 2025/09/02 12:52:42 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printd
#include <stdlib.h> //malloc
#include <unistd.h> // write, usleep
#include <sys/time.h> //gettimeofday
#include <limits.h> // INTMAX
#include <pthread.h>

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
	long	meals;
	bool	full;
	long	last_meal_time;
	pthread_t	thread_id; //philo is a thread
}	t_philo;



/*
FORK = MUTEX
./philo 8 800 200 200
*/
