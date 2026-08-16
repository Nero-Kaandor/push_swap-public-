/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:44:32 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/09 14:13:57 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns the total number of nodes in the linked list
int	lst_size(t_node *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

// Returns the last node of the list (NULL if the list is empty)
t_node	*lst_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// Checks if the list is sorted in ascending order
int	lst_is_sorted(t_node *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->number > lst->next->number)
			return (0);
		lst = lst->next;
	}
	return (1);
}
