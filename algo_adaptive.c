/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:20:21 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 11:52:16 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculates the disorder ratio based on index inversions
double	calculate_disorder(t_node *a)
{
	t_node	*i;
	t_node	*j;
	double	mistakes;
	double	total;

	mistakes = 0;
	total = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->index > j->index)
				mistakes++;
			total++;
			j = j->next;
		}
		i = i->next;
	}
	if (total == 0)
		return (0);
	return (mistakes / total);
}

// Selects and applies the best sorting strategy based on stack disorder
void	adaptive_sort(t_node **a, t_node **b, t_bench *bench)
{
	double	disorder;
	int		size;

	if (!a || !*a || lst_is_sorted(*a))
		return ;
	disorder = bench->disorder;
	size = lst_size(*a);
	if (disorder < 0.2 || size <= 20)
		simple_sort(a, b, bench);
	else if (disorder < 0.5 && size < 150)
		medium_sort(a, b, bench);
	else
		complex_sort(a, b, bench);
}
