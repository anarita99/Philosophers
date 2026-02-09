/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:11:49 by adores            #+#    #+#             */
/*   Updated: 2026/02/09 12:14:26 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->data->n_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		write_str("has taken a fork", philo);
		my_usleep(philo->data, philo->data->to_die);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	if (philo->philo_id % 2 == 0)
		usleep(200);
	pthread_mutex_lock(&philo->data->eat_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->data->eat_mutex);
	while (1)
	{
		if (check_end(philo->data))
			break ;
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}

static int	create_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		data->philos[i].last_meal_time = data->start_simulation;
		if (pthread_create(&data->philos[i].thread_id,
				NULL, routine, &data->philos[i]) != 0)
			return (1);
	}
	if (pthread_create(&data->monitor, NULL, monitor, data) != 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac != 5 && ac != 6)
	{
		printf("Error: Wrong number of arguments.\n");
		return (1);
	}
	if (set_values(&data, av) != 0)
		return (1);
	set_philo_val(&data);
	if (create_threads(&data) != 0)
		return (1);
	i = -1;
	while (++i < data.n_philos)
	{
		if (pthread_join(data.philos[i].thread_id, NULL) != 0)
			return (1);
	}
	if (pthread_join(data.monitor, NULL) != 0)
		return (1);
	destroy_mutexes(&data);
	free_data(&data);
	return (0);
}
