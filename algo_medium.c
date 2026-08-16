/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:59:27 by catsin-k          #+#    #+#             */
/*   Updated: 2026/01/28 14:30:36 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Computes an optimal chunk size based on the stack size
static int	get_chunk_size(int size)
{
	int	chunk;

	chunk = 0;
	while (chunk * chunk < size)
		chunk++;
	return (chunk);
}

// Pushes elements from stack A to stack B by chunks using index ranges
static void	push_chunks(t_node **a, t_node **b, int chunk, t_bench *bench)
{
	int	limit;

	limit = chunk;
	while (*a)
	{
		if ((*a)->index < limit)
		{
			pb(a, b, bench);
			if (*b && (*b)->index < limit - (chunk / 2) && (*b)->next != NULL)
				rb(b, bench);
		}
		else if ((*a)->next != NULL)
			ra(a, bench);
		if (!*a)
			break ;
		if (limit <= lst_size(*a) + lst_size(*b))
			limit += chunk;
	}
}

// Finds the position of the maximum index in stack B
static int	find_max_index_pos(t_node *b)
{
	int	pos;
	int	max_index;
	int	max_pos;

	pos = 0;
	max_pos = 0;
	max_index = b->index;
	while (b)
	{
		if (b->index > max_index)
		{
			max_index = b->index;
			max_pos = pos;
		}
		b = b->next;
		pos++;
	}
	return (max_pos);
}

// Pushes all elements back from stack B to stack A in sorted order
static void	push_back_to_a(t_node **a, t_node **b, t_bench *bench)
{
	int	pos;
	int	size;

	while (*b)
	{
		size = lst_size(*b);
		pos = find_max_index_pos(*b);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b, bench);
		}
		else
		{
			while (pos++ < size)
				rrb(b, bench);
		}
		pa(a, b, bench);
	}
}

// Sorts the stack using a chunk-based strategy for medium-sized inputs
void	medium_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;
	int	chunk;

	size = lst_size(*a);
	chunk = get_chunk_size(size);
	push_chunks(a, b, chunk, bench);
	push_back_to_a(a, b, bench);
}
