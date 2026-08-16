/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:25:48 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:02:37 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

// Initialize benchmark counters and default settings
void	bench_init(t_bench *bench)
{
	if (!bench)
		return ;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->disorder = 0.0;
	bench->strategy = STRAT_ADAPTIVE;
}

// Increment the benchmark counter for a given operation
void	bench_count(t_bench *bench, t_op op)
{
	if (!bench)
		return ;
	if (op == OP_SA)
		bench->sa++;
	else if (op == OP_SB)
		bench->sb++;
	else if (op == OP_SS)
		bench->ss++;
	else if (op == OP_PA)
		bench->pa++;
	else if (op == OP_PB)
		bench->pb++;
	else if (op == OP_RA)
		bench->ra++;
	else if (op == OP_RB)
		bench->rb++;
	else if (op == OP_RR)
		bench->rr++;
	else if (op == OP_RRA)
		bench->rra++;
	else if (op == OP_RRB)
		bench->rrb++;
	else if (op == OP_RRR)
		bench->rrr++;
}

// Print detailed operation counters
static void	print_ops(t_bench *b)
{
	ft_printf_bench("[bench] sa: %d sb: %d ss: %d ", (int)b->sa, (int)b->sb,
		(int)b->ss);
	ft_printf_bench("pa: %d pb: %d\n", (int)b->pa, (int)b->pb);
	ft_printf_bench("[bench] ra: %d rb: %d rr: %d ", (int)b->ra, (int)b->rb,
		(int)b->rr);
	ft_printf_bench("rra: %d rrb: %d rrr: %d\n", (int)b->rra, (int)b->rrb,
		(int)b->rrr);
}

// Display benchmark results and strategy information
void	bench_print(t_bench *b)
{
	if (!b)
		return ;
	print_disorder(b->disorder);
	if (b->strategy == STRAT_ADAPTIVE)
	{
		if (b->disorder < 0.2)
			ft_printf_bench("[bench] strategy: Adaptive / O(n²)\n");
		else if (b->disorder < 0.5)
			ft_printf_bench("[bench] strategy: Adaptive / O(n√n)\n");
		else
			ft_printf_bench("[bench] strategy: Adaptive / O(n log n)\n");
	}
	else if (b->strategy == STRAT_SIMPLE)
		ft_printf_bench("[bench] strategy: Simple / O(n²)\n");
	else if (b->strategy == STRAT_MEDIUM)
		ft_printf_bench("[bench] strategy: Medium / O(n√n)\n");
	else
		ft_printf_bench("[bench] strategy: Complex / O(n log n)\n");
	ft_printf_bench("[bench] total_ops: %d\n", total_ops(b));
	print_ops(b);
}
