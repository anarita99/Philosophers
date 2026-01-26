/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:42:28 by adores            #+#    #+#             */
/*   Updated: 2026/01/23 20:16:37 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dead_function(t_philo *philo)
{
	unsigned long	timestamp;

	pthread_mutex_lock(&philo->data->print_mutex);
	timestamp = get_time() - philo->data->start_simulation;
	printf("%lu %d died\n", timestamp, philo->philo_id);
	pthread_mutex_lock(&philo->data->end);
	philo->data->end_simulation = true;
	pthread_mutex_unlock(&philo->data->end);
	usleep(500);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	they_are_full(t_data *data)
{
	if (data->full == data->n_philos)
	{
		pthread_mutex_lock(&data->end);
		data->end_simulation = true;
		pthread_mutex_unlock(&data->end);
		return (0);
	}
	return (1);
}

void	*monitor(void *data_copy)
{
	int		i;
	t_data	*data;

	data = (t_data *)data_copy;
	while (1)
	{
		i = -1;
		data->full = 0;
		while (++i < data->n_philos)
		{
			pthread_mutex_lock(&data->eat_mutex);
			if (data->philos[i].nb_of_meals == data->limit_meals)
				data->full++;
			if (get_time() - data->philos[i].last_meal_time > data->to_die)
			{
				dead_function(&data->philos[i]);
				return (pthread_mutex_unlock(&data->eat_mutex), NULL);
			}
			pthread_mutex_unlock(&data->eat_mutex);
		}
		if (they_are_full(data) == 0)
			break ;
		usleep(100);
	}
	return (NULL);
}
