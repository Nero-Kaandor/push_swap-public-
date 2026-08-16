/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:18:41 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:03:05 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Allocates and initializes a new list node with the given value
t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		error_exit();
	node->number = value;
	node->index = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

// adds a node to the end of the linked list
void	add_node_end(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

// Converts an integer array into a doubly linked list and assigns indexes
t_node	*tab_to_list(int *tab, int size)
{
	t_node	*lst;
	int		i;

	lst = NULL;
	i = 0;
	while (i < size)
	{
		add_node_end(&lst, new_node(tab[i]));
		i++;
	}
	set_indexes(lst);
	return (lst);
}

// Assigns an index to each node based on its relative value order
void	set_indexes(t_node *lst)
{
	t_node	*current;
	t_node	*cmp;
	int		index;

	current = lst;
	while (current)
	{
		index = 0;
		cmp = lst;
		while (cmp)
		{
			if (cmp->number < current->number)
				index++;
			cmp = cmp->next;
		}
		current->index = index;
		current = current->next;
	}
}
