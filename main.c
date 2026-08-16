/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:49:40 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:03:25 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "flags.h"
#include "push_swap.h"

void	init_flags(t_flags *flags)
{
	flags->strategy = STRAT_ADAPTIVE;
	flags->isbench = 0;
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_flags	flags;
	int		old_ac;

	if (ac < 2)
		return (0);
	b = NULL;
	init_flags(&flags);
	old_ac = ac;
	a = parse_args(ac, av, &flags, old_ac);
	if (a)
		run_sort(&a, &b, &flags);
	free_all(&a, &b);
	return (0);
}
