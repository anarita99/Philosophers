/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:19:31 by adores            #+#    #+#             */
/*   Updated: 2026/01/14 15:00:46 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor_eat(t_philo *philo);

void	is_eating(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		write_str("has taken a fork", philo);
		pthread_mutex_lock(philo->right_fork);
		write_str("has taken a fork", philo);
		write_str("is eating", philo);
		monitor_eat(philo);
		my_usleep(philo->data, philo->data->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		write_str("has taken a fork", philo);
		pthread_mutex_lock(philo->left_fork);
		write_str("has taken a fork", philo);
		write_str("is eating", philo);
		monitor_eat(philo);
		my_usleep(philo->data, philo->data->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	monitor_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_mutex);
	//my_usleep(philo->data, philo->data->time_to_eat);
	philo->last_meal_time = get_curr_time();
	philo->nb_of_meals++;
	pthread_mutex_unlock(&philo->data->eat_mutex);
}

void 	is_thinking(t_philo *philo)
{
	int	think;

	if(philo->data->n_philos % 2 == 0)
		return;
	think = philo->data->time_to_eat * 2 - philo->data->time_to_sleep;
	if (think < 0)
		think = philo->data->time_to_eat * 0.1;
	write_str("is thinking", philo);
	my_usleep(philo->data, (think));
}

void 	is_sleeping(t_philo	*philo)
{
	write_str("is sleeping", philo);
	my_usleep(philo->data, philo->data->time_to_sleep);
}

int check_end(t_data *data)
{
	pthread_mutex_lock(&data->end);
	if (data->end_simulation == true)
		return (pthread_mutex_unlock(&data->end), 1);
	return (pthread_mutex_unlock(&data->end), 0);
}


