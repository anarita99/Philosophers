/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:11:49 by adores            #+#    #+#             */
/*   Updated: 2026/01/07 16:15:50 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(t_data *data)
{
	data->philos->last_meal_time = get_curr_time();
	while(1)
	{
		if(check_end(data))
			break;
		is_eating(data->philos);
		is_sleeping(data);
		is_thinking(data);
	}
	
}

int main(int ac, char **av)
{
	t_data	data;
	unsigned long i;

	if(ac != 5 && ac != 6)
	{
		printf("Error: Wrong number of arguments.");
		return 1;
	}
	else
	{
		set_values(&data, av);
		set_philo_val(&data);
		//parsing input
		//creating the data
		//dinner start
		//no leaks
	}
	
	i = 0;
	while(i < data.n_philos)
	{
		if(pthread_create(&data.philos[i].thread_id, NULL, routine, NULL) != 0)
			return 1;
		
		i++;
	}
	if(pthread_create(&data.monitor, NULL, monitor, NULL) != 0)
		return 1;
	i = 0;
	while(i < data.n_philos)
	{
		if(pthread_join(&data.philos[i].thread_id, NULL) != 0)
			return 1;
		printf("Thread %ld has finished\n", i);
		i++;
	}
	return(0);
}


/*gcc -g -pthread main.c*/