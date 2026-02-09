/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:27:21 by adores            #+#    #+#             */
/*   Updated: 2026/02/09 12:15:18 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_str(char *str, t_philo *philo)
{
	unsigned long	timestamp;

	pthread_mutex_lock(&philo->data->print_mutex);
	if (check_end(philo->data))
	{
		pthread_mutex_unlock(&philo->data->print_mutex);
		return ;
	}
	timestamp = get_time() - philo->data->start_simulation;
	printf("%lu %d %s\n", timestamp, philo->philo_id, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->end);
	pthread_mutex_destroy(&data->eat_mutex);
}

void	my_usleep(t_data *data, unsigned long time)
{
	unsigned long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
	{
		usleep(500);
		if (check_end(data))
			break ;
	}
}

int	malloc_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	if (!data->philos)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (free(data->philos), 1);
	return (0);
}

void	free_data(t_data *data)
{
	free(data->philos);
	free(data->forks);
}
