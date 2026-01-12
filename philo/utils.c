/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:27:21 by adores            #+#    #+#             */
/*   Updated: 2026/01/08 16:04:34 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_str(char *str, t_philo *philo)
{
	unsigned long timestamp;

	pthread_mutex_lock(&philo->data->print_mutex);
	if(philo->data->end_simulation == true)
	{
		pthread_mutex_unlock(&philo->data->print_mutex) ;
		return ;
	}
	timestamp = get_curr_time() - philo->data->start_simulation;
	printf(" %lu %d %s\n", timestamp, philo->philo_id, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void destroy_mutexes(t_data *data)
{
	int i;

	i = 0;
	while(i < data->n_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->end);
	pthread_mutex_destroy(&data->eat_mutex);
}