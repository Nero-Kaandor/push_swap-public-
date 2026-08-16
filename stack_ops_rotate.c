/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:38:15 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:02:58 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

// Rotate a stack by moving the first element to the end
static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = lst_last(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

// Perform the rotate operation on stack A
void	ra(t_node **a, t_bench *bench)
{
	rotate(a);
	write(1, "ra\n", 3);
	bench_count(bench, OP_RA);
}

// Perform the rotate operation on stack B
void	rb(t_node **b, t_bench *bench)
{
	rotate(b);
	write(1, "rb\n", 3);
	bench_count(bench, OP_RB);
}

// Perform the rotate operation on both stacks
void	rr(t_node **a, t_node **b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	bench_count(bench, OP_RR);
}
