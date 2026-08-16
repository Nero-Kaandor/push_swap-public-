/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_printf_bench_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:15:08 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 11:51:29 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Print the disorder ratio as a percentage
void	print_disorder(double disorder)
{
	int	pct;

	pct = (int)(disorder * 10000);
	if (pct < 0)
		pct = -pct;
	ft_printf_bench("[bench] disorder: %d.", pct / 100);
	if (pct % 100 < 10)
		ft_printf_bench("0");
	ft_printf_bench("%d%%\n", pct % 100);
}

// Compute the total number of operations performed
int	total_ops(t_bench *b)
{
	return (b->sa + b->sb + b->ss + b->pa + b->pb + b->ra + b->rb + b->rr
		+ b->rra + b->rrb + b->rrr);
}
