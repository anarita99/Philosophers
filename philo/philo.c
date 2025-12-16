/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:11:49 by adores            #+#    #+#             */
/*   Updated: 2025/12/16 17:23:14 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
pthread_mutex_t mutex;
void *routine()
{
	int i = 0;
	int nums = 0;
	
	while(i < 100)
	{
		pthread_mutex_lock(&mutex);
		i++;
		nums++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(int ac, char **av)
{
	
	pthread_t threads[5];
	t_data	*data;
	/*if(ac != 5 || ac != 6)
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
	int i = 0;
	pthread_mutex_init(&mutex, NULL);
	while(i < 5)
	{
		if(pthread_create(&threads[i], NULL, routine, NULL) != 0)
			return 1;
		printf("Thread %d has started\n", i);
		i++;
	}
	i = 0;
	while(i < 5)
	{
		if(pthread_join(threads[i], NULL) != 0)
			return 1;
		printf("Thread %d has finished\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	return(0);
}


/*gcc -g -pthread main.c*/