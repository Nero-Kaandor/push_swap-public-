/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:56:23 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:03:01 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

// Push the top element from stack B to stack A
void	pa(t_node **a, t_node **b, t_bench *bench)
{
	t_node	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	tmp->prev = NULL;
	*a = tmp;
	write(1, "pa\n", 3);
	bench_count(bench, OP_PA);
}

// Push the top element from stack A to stack B
void	pb(t_node **a, t_node **b, t_bench *bench)
{
	t_node	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	tmp->prev = NULL;
	*b = tmp;
	write(1, "pb\n", 3);
	bench_count(bench, OP_PB);
}
