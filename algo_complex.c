/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:06:47 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 11:49:31 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Determine the number of bits required to represent the maximum index
int	get_max_bits(t_node *a)
{
	int	index_max;
	int	bits;

	index_max = 0;
	while (a)
	{
		if (a->index > index_max)
			index_max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((index_max >> bits) != 0)
		bits++;
	return (bits);
}

// Sort the stack using a radix-based (bitwise) sorting algorithm
void	complex_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	bit;
	int	size;
	int	i;
	int	max_bits;

	if (!a || !*a || lst_is_sorted(*a))
		return ;
	max_bits = get_max_bits(*a);
	size = lst_size(*a);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->index >> bit) & 1)
				ra(a, bench);
			else
				pb(a, b, bench);
			i++;
		}
		while (*b)
			pa(a, b, bench);
		bit++;
	}
}
