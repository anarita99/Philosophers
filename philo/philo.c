/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:11:49 by adores            #+#    #+#             */
/*   Updated: 2026/01/06 16:04:44 by adores           ###   ########.fr       */
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

void monitor(t_data *data)
{
	int i;
	int full;

	i = 0;
	while(1)
	{
		while(i < data->n_philos)
		{
			if(data->philos[i].nb_of_meals == data->limit_meals)
				full++;
			if(get_curr_time() - data->philos[i].last_meal_time > data->time_to_die)
				
			i++;
		}
		if(full == data->n_philos)
		{
			pthread_mutex_lock(&data->end);
			data->end_simulation = true;
			pthread_mutex_unlock(&data->end);
			break;
		}
			
	}
}

int main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	set_values(&data, av);
	set_philo_val(&data);
	pthread_t threads[data.n_philos];
	/*if(ac != 5 && ac != 6)
	{
		printf("Error: Wrong number of arguments.");
		return 1;
	}
	else
	{
		//parsing input
		//creating the data
		//dinner start
		//no leaks
	}*/
	unsigned long i = 0;
	while(i < data.n_philos)
	{
		if(pthread_create(&data.philos[i].thread_id, NULL, routine, NULL) != 0)
			return 1;
		
		i++;
	}
	
	//monitor
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