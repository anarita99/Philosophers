/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:37:06 by adores            #+#    #+#             */
/*   Updated: 2025/12/14 12:05:54 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_values(t_data *data, int ac, char **av)
{

	data->n_philos = char_to_num(av[1]);
	data->time_to_die = char_to_num(av[2]) * 1000;
	data->time_to_eat = char_to_num(av[3]) * 1000;
	data->time_to_sleep = char_to_num(av[4]) * 1000;
	if(av[5])
		data->limit_meals = char_to_num(av[5]) * 1000;
	
}

void	malloc_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	data->forks = malloc(sizeof(t_fork) * data->n_philos);
}