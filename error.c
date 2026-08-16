/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:05:47 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 11:49:42 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	check_duplicates(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	if (size <= 1)
		return (0);
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	test_args(char **av, int start)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	if (av[i][j] == '\0')
		return (1);
	while (av[i])
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			test_char(&av[i][j]);
			if ((is_number(&av[i][j]) && is_add_subscribe(&av[i][j + 1]))
				|| (is_add_subscribe(&av[i][j]) && is_add_subscribe(&av[i][j
						+ 1])))
				error_exit();
			else if (i > start && is_number(&av[i][j]) && !is_number(&av[i][j
					+ 1]) && (av[i][j + 1] != 0))
				error_exit();
			j++;
		}
		i++;
	}
	return (0);
}

void	test_char(char *c)
{
	if (!ft_isdigit(*c) && *c != ' ' && *c != '+' && *c != '-')
	{
		error_exit();
	}
}
