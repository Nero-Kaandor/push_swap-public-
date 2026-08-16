/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:07:37 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/09 14:31:39 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_split_args(char **new_av, int start, int total_ac, int old_ac)
{
	int	i;
	int	nb_mots_split;

	if (!new_av)
		return ;
	nb_mots_split = total_ac - (old_ac - 1);
	i = start;
	while (i < start + nb_mots_split)
	{
		free(new_av[i]);
		i++;
	}
	free(new_av);
}

void	free_all(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
}
