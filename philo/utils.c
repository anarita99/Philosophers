/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:27:21 by adores            #+#    #+#             */
/*   Updated: 2026/01/15 15:03:04 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_str(char *str, t_philo *philo)
{
	unsigned long	timestamp;

	if (check_end(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
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

void	free_data(t_data *data)
{
	free(data->philos);
	free(data->forks);
}
