/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:11:49 by adores            #+#    #+#             */
/*   Updated: 2025/12/26 15:40:40 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex;
void *routine()
{
	t_data *data;
	pthread_mutex_lock(&mutex);
	is_eating(data->philos);
	is_thinking();
	is_sleeping();
	pthread_mutex_unlock(&mutex);
}

int main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	set_values(&data, av);
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
	pthread_mutex_init(&mutex, NULL);
	while(i < data.n_philos)
	{
		if(pthread_create(&threads[i], NULL, routine, NULL) != 0)
			return 1;
		printf("Thread %ld has started\n", i);
		i++;
	}
	//monitor
	i = 0;
	while(i < data.n_philos)
	{
		if(pthread_join(threads[i], NULL) != 0)
			return 1;
		printf("Thread %ld has finished\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	return(0);
}


/*gcc -g -pthread main.c*/