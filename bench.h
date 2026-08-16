/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:29 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:23:01 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_H
# define BENCH_H

# include "flags.h"

// Enumeration of all supported stack operations
typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}				t_op;

// Structure used to benchmark sorting operations and strategies
typedef struct s_bench
{
	long		sa;
	long		sb;
	long		ss;
	long		pa;
	long		pb;
	long		ra;
	long		rb;
	long		rr;
	long		rra;
	long		rrb;
	long		rrr;
	double		disorder;
	t_strategy	strategy;

}				t_bench;

/* bench core */
void			bench_init(t_bench *bench);
void			bench_count(t_bench *bench, t_op op);
void			bench_print(t_bench *bench);

#endif
