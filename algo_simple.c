/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:16:15 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/09 14:06:03 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "push_swap.h"

// Sort a stack of exactly three elements
static void	sort_three(t_node **a, t_bench *bench)
{
	int	i;
	int	j;
	int	k;

	if ((*a)->next->next != NULL)
	{
		i = (*a)->number;
		j = (*a)->next->number;
		k = (*a)->next->next->number;
		if (i > j && i > k)
			ra(a, bench);
		else if (j > i && j > k)
			rra(a, bench);
		if ((*a)->number > (*a)->next->number)
			sa(a, bench);
	}
}

// Return the position of the minimum value in the stack
static int	get_min_pos(t_node *a)
{
	int	min_value;
	int	pos;
	int	i;

	min_value = a->number;
	pos = 0;
	i = 0;
	while (a)
	{
		if (a->number < min_value)
		{
			min_value = a->number;
			pos = i;
		}
		i++;
		a = a->next;
	}
	return (pos);
}

// Reduce the stack to three elements by pushing minima to stack B
void	reduce_to_three(t_node **a, t_node **b, t_bench *bench)
{
	int	pos;
	int	size;

	size = lst_size(*a);
	while (size > 3)
	{
		pos = get_min_pos(*a);
		if (pos <= size / 2)
			while (pos-- > 0)
				ra(a, bench);
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rra(a, bench);
		}
		pb(a, b, bench);
		size--;
	}
}

// Simple sorting strategy for small stack sizes
void	simple_sort(t_node **a, t_node **b, t_bench *bench)
{
	if ((*a)->next->next == NULL)
	{
		if ((*a)->number > (*a)->next->number)
			sa(a, bench);
		return ;
	}
	reduce_to_three(a, b, bench);
	sort_three(a, bench);
	while (*b)
		pa(a, b, bench);
}
