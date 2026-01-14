/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:50:19 by adores            #+#    #+#             */
/*   Updated: 2026/01/14 15:07:06 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	char_to_num(const char *str)
{
	long		i;
	long	result;

	result = 0;
	i = 0;
	if (str[i] == '\0')
		return (-1);
	while(str[i])
	{
		if (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			return (-1);
		else if (str[i] == '+' || str[i] == '-')
			return (-1);
		else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			return (-1);
		else if(str[i] >= '0' && str[i] <= '9')
		{
			if (result > (INT_MAX - (str[i] - '0')) / 10)
				return (-1);
			result = result * 10 + str[i] - 48;
		}
		i++;
	}
	return(result);
}
