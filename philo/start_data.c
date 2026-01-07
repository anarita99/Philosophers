/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:37:06 by adores            #+#    #+#             */
/*   Updated: 2026/01/07 16:11:17 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_data(t_data *data);

unsigned long	get_curr_time(void)
{
	unsigned long	curr_time;
	struct timeval time;

	gettimeofday(&time, NULL);
	curr_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (curr_time);
}

void	set_values(t_data *data, char **av)
{
	data->n_philos = char_to_num(av[1]);
	if(data->n_philos <= 0 || data->n_philos > 200)
	{
		printf("Error: Invalid number of philosophers.\n");
		return ;
	}
	data->time_to_die = char_to_num(av[2]);
	data->time_to_eat = char_to_num(av[3]);
	data->time_to_sleep = char_to_num(av[4]);
	if(av[5])
		data->limit_meals = char_to_num(av[5]);
	else
		data->limit_meals = -1;
	data->full = 0;
	if(data->time_to_die <= 0 || data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (printf("Error: Time must be positive\n")) ;
	if (malloc_data(data) != 0)
		return ;
	data->end_simulation = false;
	data->start_simulation = get_curr_time();
}

void initialize_mutex(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->n_philos)
	{
		if(pthread_mutex_init(&data->forks[i], NULL))
			return ;
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL))
		return ;
	if (pthread_mutex_init(&data->end, NULL))
		return ;
	if (pthread_mutex_init(&data->eat_mutex, NULL))
		return ;
}

void set_philo_val(t_data *data)
{
	int i;

	i = 0;
	while(i < data->n_philos)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].nb_of_meals = 0;
		data->philos[i].full = false;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->n_philos];
		i++;
	}
	
}

int	malloc_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	if(!data->philos)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if(!data->forks)
		return (free(data->philos), 1);
	return (0);
}

void	free_data(t_data *data)
{
	free(data->philos);
	free(data->forks);
}