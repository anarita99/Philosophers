/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:37:06 by adores            #+#    #+#             */
/*   Updated: 2025/12/17 15:56:49 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_data(t_data *data);

unsigned long	get_curr_time(void)
{
	unsigned long	curr_time;
	struct timeval time;

	gettimeofday(&time, NULL);
	curr_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (curr_time);
}

void	set_values(t_data *data, char **av)
{
	if (malloc_data(data) != 0)
		return ;
	data->n_philos = char_to_num(av[1]);
	//data->time_to_die = char_to_num(av[2]);
	data->time_to_eat = char_to_num(av[3]);
	data->time_to_sleep = char_to_num(av[4]);
	//if(av[5])
	//	data->limit_meals = char_to_num(av[5]);
	//else
	//	data->limit_meals = -1;
}

int	malloc_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	if(!data->philos)
		return 1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if(!data->forks)
		return 1;
}

void	free_data(t_data *data)
{
	free(data->philos);
	free(data->forks);
}