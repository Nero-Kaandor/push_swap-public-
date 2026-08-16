/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:37:47 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:03:00 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

// Rotate a stack by moving the last element to the front
static void	reverse_rotate(t_node **lst)
{
	t_node	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	last = *lst;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *lst;
	(*lst)->prev = last;
	*lst = last;
}

// Perform the rotate operation on stack A
void	rra(t_node **a, t_bench *bench)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	bench_count(bench, OP_RRA);
}

// Perform the rotate operation on stack B
void	rrb(t_node **b, t_bench *bench)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	bench_count(bench, OP_RRB);
}

// Perform the rotate operation on both stacks
void	rrr(t_node **a, t_node **b, t_bench *bench)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	bench_count(bench, OP_RRR);
}
