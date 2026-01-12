/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:11:49 by adores            #+#    #+#             */
/*   Updated: 2026/01/09 11:35:18 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->last_meal_time = get_curr_time();
	while(1)
	{
		if(check_end(philo->data))
			break;
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}

int main(int ac, char **av)
{
	t_data	data;
	int i;

	if(ac != 5 && ac != 6)
	{
		printf("Error: Wrong number of arguments.");
		return (1);
	}
	if (set_values(&data, av) != 0)
		return (1);
	set_philo_val(&data);
	i = -1;
	while(++i < data.n_philos)
	{
		data.philos[i].last_meal_time = data.start_simulation;
		if(pthread_create(&data.philos[i].thread_id, NULL, routine, &data.philos[i]) != 0)
			return (1);
	}
	if(pthread_create(&data.monitor, NULL, monitor, &data) != 0)
		return (1);
	i = -1;
	while(++i < data.n_philos)
	{
		if(pthread_join(data.philos[i].thread_id, NULL) != 0)
			return (1);
	}
	if(pthread_join(data.monitor, NULL) != 0)
			return (1);
	free_data(&data);
	destroy_mutexes(&data);
	return(0);
}

/*gcc -g -pthread main.c*/