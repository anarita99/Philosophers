/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:19:31 by adores            #+#    #+#             */
/*   Updated: 2025/12/26 15:55:04 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor_eat(t_philo *philo);

void	is_eating(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		printf("has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		printf("has taken a fork");
		printf("is eating\n");
		monitor_eat(philo);
		usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		printf("has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		printf("has taken a fork");
		printf("is eating\n");
		monitor_eat(philo);
		usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	monitor_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->monitor);
	philo->last_meal_time = get_curr_time();
	philo->nb_of_meals++;
	pthread_mutex_unlock(&philo->data->monitor);
}

void 	is_thinking(void)
{
	printf("is thinking\n");
}

void 	is_sleeping(void)
{
	t_data	*data;

	usleep(data->time_to_sleep / 1000);
	write_str("is sleeping", data->philos->philo_id);
	
}

void sleep_cycle(t_data *data)
{
	unsigned long	start_time;
	unsigned long	now_time;

	usleep(data->time_to_sleep);
}