/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:50:12 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:03:23 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// allows you to convert a string into a long numeric value
long	ft_atol(char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!ft_isdigit(*s))
		error_exit();
	while (*s && ft_isdigit(*s))
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	if (*s != '\0')
		error_exit();
	return (res * sign);
}

// allows you to compare two strings
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
