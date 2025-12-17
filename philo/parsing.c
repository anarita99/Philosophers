/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:50:19 by adores            #+#    #+#             */
/*   Updated: 2025/12/17 11:46:30 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ./philo 5      800  200    200     [5]
         av[1]   av[2] av[3]  av[4]  av[5]
1. actual  numbers
2.not > INT MAX
3.timestamps > 60ms

*/

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
/*
int main(int ac, char **av)
{
	long *nums = malloc(sizeof(long) * ac - 1);
	int i = 0;
	while(i < ac -1)
	{
		nums[i] = parse_number(av[i + 1]);
		i++;
	}
	i = 0;
	while(i < ac - 1)
	{
		printf("%ld ", nums[i]);
		i++;
	}
	printf("\n");
}*/