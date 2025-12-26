/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:27:21 by adores            #+#    #+#             */
/*   Updated: 2025/12/26 15:31:40 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_str(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%lu %s", philo->philo_id, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
}