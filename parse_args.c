/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:47:26 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:03:19 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "push_swap.h"

// Builds a new argv by replacing one argument with its split version
char	**build_new_av(char **av, char **split, int start, int *ac)
{
	char	**new_av;
	int		i;
	int		j;

	new_av = malloc(sizeof(char *) * (*ac + count_splits(split)));
	if (!new_av)
		return (NULL);
	i = 0;
	while (i < start)
	{
		new_av[i] = av[i];
		i++;
	}
	j = 0;
	while (split[j])
		new_av[i++] = split[j++];
	j = start + 1;
	while (j < *ac)
		new_av[i++] = av[j++];
	new_av[i] = NULL;
	*ac = i;
	return (new_av);
}

// Prepares arguments by splitting a spaced argument if needed
char	**prepare_args(int *ac, char **av, int start)
{
	char	**split;
	char	**new_av;

	new_av = NULL;
	split = NULL;
	if (start >= *ac || !ft_strchr(av[start], ' '))
	{
		return (av);
	}
	split = ft_split(av[start], ' ');
	if (!split)
		return (NULL);
	if (!split[0])
	{
		free(split);
		return (NULL);
	}
	new_av = build_new_av(av, split, start, ac);
	free(split);
	return (new_av);
}

// Converts argument strings into an integer array starting from a given index
int	*args_to_tab(int ac, char **av, int start)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * (ac - start));
	if (!tab)
		error_exit();
	while (start < ac && av[start][0] != '\0')
	{
		tab[i] = (int)ft_atol(av[start]);
		i++;
		start++;
	}
	return (tab);
}

// Checks if there are no arguments left after parsing
static int	last_test_args(int ac, char **new_av, char **av, int start)
{
	if (start >= ac)
	{
		if (new_av != av)
			free(new_av);
		return (1);
	}
	return (0);
}

// Parses arguments, handles flags, splits, validation, and builds the stack
t_node	*parse_args(int ac, char **av, t_flags *flags, int old_ac)
{
	int		start;
	int		*tab;
	t_node	*a;
	char	**new_av;

	start = parse_flags(ac, av, flags);
	if (test_args(av, start) == 1 && ac - start != 1)
		return (a = NULL);
	new_av = prepare_args(&ac, av, start);
	if (!new_av)
		error_exit();
	if (last_test_args(ac, new_av, av, start))
		return (NULL);
	tab = args_to_tab(ac, new_av, start);
	if (check_duplicates(tab, ac - start))
	{
		if (new_av != av)
			free_split_args(new_av, start, ac, old_ac);
		free(tab);
		error_exit();
	}
	a = tab_to_list(tab, ac - start);
	if (new_av != av)
		free_split_args(new_av, start, ac, old_ac);
	return (free(tab), a);
}
