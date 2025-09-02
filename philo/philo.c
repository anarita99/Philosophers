/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:11:49 by adores            #+#    #+#             */
/*   Updated: 2025/09/02 12:41:19 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *computation(void *add)
{
	long *addnum = (long *)add;
	printf("Add: %ld\n", *addnum);
	return (NULL);
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	long value1 = 1;
	long value2 = 2;
	pthread_create(&thread1, NULL, computation, (void*) &value1);
	pthread_create(&thread2, NULL, computation, (void*) &value2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return(0);
}


/*gcc -g -pthread main.c*/