/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:31:18 by catsin-k          #+#    #+#             */
/*   Updated: 2026/01/26 14:46:47 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "flags.h"
#include "push_swap.h"

// Assign the selected sorting strategy to the benchmark structure
static void	set_strategy_name(t_bench *bench, t_flags *flags)
{
	if (!bench || !flags)
		return ;
	bench->strategy = flags->strategy;
}

// Execute the appropriate sorting strategy based on flags
static void	run_strategy(t_node **a, t_node **b, t_flags *flags, t_bench *bench)
{
	if (flags->strategy == STRAT_SIMPLE)
		simple_sort(a, b, bench);
	else if (flags->strategy == STRAT_MEDIUM)
		medium_sort(a, b, bench);
	else if (flags->strategy == STRAT_COMPLEX)
		complex_sort(a, b, bench);
	else
		adaptive_sort(a, b, bench);
}

// Main entry point for sorting logic and benchmarking
void	run_sort(t_node **a, t_node **b, t_flags *flags)
{
	t_bench	bench;

	if (!a || !*a)
		return ;
	bench_init(&bench);
	set_strategy_name(&bench, flags);
	bench.disorder = calculate_disorder(*a);
	if (bench.disorder == 0)
	{
		if (flags->isbench)
			bench_print(&bench);
		return ;
	}
	run_strategy(a, b, flags, &bench);
	if (flags->isbench)
		bench_print(&bench);
}
