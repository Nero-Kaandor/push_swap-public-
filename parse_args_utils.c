/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:22:24 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:03:21 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Locate the first occurrence of a character in a string
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

// Count the number of strings in a NULL-terminated array
int	count_splits(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}

int	is_add_subscribe(char *c)
{
	if (*c == '+' || *c == '-')
		return (1);
	else
		return (0);
}

int	is_space(char *c)
{
	if (*c == ' ')
		return (1);
	else
		return (0);
}

int	is_number(char *c)
{
	if (ft_isdigit(*c))
		return (1);
	else
		return (0);
}
