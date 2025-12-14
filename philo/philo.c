/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:11:49 by adores            #+#    #+#             */
/*   Updated: 2025/12/14 11:36:38 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *add)
{
	long *addnum = (long *)add;
	printf("Add: %ld\n", *addnum);
	return (NULL);
}

int main(int ac, char **av)
{
	
	pthread_t thread1;
	pthread_t thread2;
	t_data	*data;
	long value1 = 1;
	long value2 = 2;

	if(ac != 5 || ac != 6)
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
	}
	pthread_create(&thread1, NULL, routine, (void*) &value1);
	pthread_create(&thread2, NULL, routine, (void*) &value2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return(0);
}


/*gcc -g -pthread main.c*/