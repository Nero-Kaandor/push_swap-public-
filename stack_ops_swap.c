/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:37:54 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:02:55 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

// Swap the first two elements of a doubly linked list
static void	swap(t_node **lst)
{
	t_node	*first;
	t_node	*second;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*lst = second;
}

// Perform the swap operation on stack A
void	sa(t_node **a, t_bench *bench)
{
	swap(a);
	write(1, "sa\n", 3);
	bench_count(bench, OP_SA);
}

// Perform the swap operation on stack B
void	sb(t_node **b, t_bench *bench)
{
	swap(b);
	write(1, "sb\n", 3);
	bench_count(bench, OP_SB);
}

// Perform the swap operation on both stacks
void	ss(t_node **a, t_node **b, t_bench *bench)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	bench_count(bench, OP_SS);
}
