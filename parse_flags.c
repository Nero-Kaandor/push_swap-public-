/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:44:07 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:04:50 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "push_swap.h"

// Checks whether the given string is a valid flag
static int	is_flag(char *s)
{
	if (!s)
		return (0);
	if (!ft_strcmp(s, "--simple") || !ft_strcmp(s, "--medium") || !ft_strcmp(s,
			"--complex") || !ft_strcmp(s, "--adaptive") || !ft_strcmp(s,
			"--bench"))
		return (1);
	return (0);
}

// Sets the corresponding flag value based on the given string
static void	set_flag(t_flags *flags, char *s)
{
	if (!ft_strcmp(s, "--simple"))
		flags->strategy = STRAT_SIMPLE;
	else if (!ft_strcmp(s, "--medium"))
		flags->strategy = STRAT_MEDIUM;
	else if (!ft_strcmp(s, "--complex"))
		flags->strategy = STRAT_COMPLEX;
	else if (!ft_strcmp(s, "--adaptive"))
		flags->strategy = STRAT_ADAPTIVE;
	else if (!ft_strcmp(s, "--bench"))
		flags->isbench = 1;
}

// Parses command-line flags and returns the index of the first argument
int	parse_flags(int ac, char **av, t_flags *flags)
{
	int	i;

	i = 1;
	while (i < ac && is_flag(av[i]))
	{
		set_flag(flags, av[i]);
		i++;
	}
	return (i);
}
