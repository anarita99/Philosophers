/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:42:28 by adores            #+#    #+#             */
/*   Updated: 2026/01/08 14:35:58 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dead_function(t_data *data)
{
	unsigned long	timestamp;

	pthread_mutex_lock(&data->print_mutex);
	timestamp = get_curr_time() - data->start_simulation;
	printf("%lu %d died\n", timestamp, data->philos->philo_id);
	pthread_mutex_lock(&data->end);
	data->end_simulation = true;
	pthread_mutex_unlock(&data->end);
	usleep(500);
	pthread_mutex_unlock(&data->print_mutex);
}

void	*monitor(void *data_copy)
{
	unsigned long i;
	t_data	*data;

	data = (t_data *)data_copy;
	i = -1;
	while(1)
	{
		data->full = 0;
		while(++i < data->n_philos)
		{
			pthread_mutex_lock(&data->eat_mutex);
			if(data->philos[i].nb_of_meals == data->limit_meals)
				data->full++;
			if(get_curr_time() - data->philos[i].last_meal_time > data->time_to_die)
			{
				dead_function(data);
				return(pthread_mutex_unlock(&data->eat_mutex), NULL) ;
			}
			pthread_mutex_unlock(&data->eat_mutex);
		}
		if(data->full == data->n_philos)
		{
			pthread_mutex_lock(&data->end);
			data->end_simulation = true;
			pthread_mutex_unlock(&data->end);
			break;
		}		
	}
	return (NULL);
}
