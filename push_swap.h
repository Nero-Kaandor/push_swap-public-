/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:10:31 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:03:08 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "bench.h"
# include "flags.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/* list structure */
typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

/* parsing */
t_node				*parse_args(int ac, char **av, t_flags *flags, int old_ac);
int					test_args(char **av, int start);

/* stack build */
t_node				*new_node(int value);
t_node				*tab_to_list(int *tab, int size);
void				add_node_end(t_node **lst, t_node *new);
void				set_indexes(t_node *lst);

/* stack utils */
int					lst_size(t_node *lst);
int					lst_is_sorted(t_node *lst);
t_node				*lst_last(t_node *lst);

/* printf_bench */
int					ft_printf_bench(char *format, ...);
void				print_disorder(double disorder);
int					total_ops(t_bench *b);

/* operations */
void				pa(t_node **a, t_node **b, t_bench *bench);
void				pb(t_node **a, t_node **b, t_bench *bench);
void				sa(t_node **a, t_bench *bench);
void				sb(t_node **b, t_bench *bench);
void				ss(t_node **a, t_node **b, t_bench *bench);
void				ra(t_node **a, t_bench *bench);
void				rb(t_node **b, t_bench *bench);
void				rr(t_node **a, t_node **b, t_bench *bench);
void				rra(t_node **a, t_bench *bench);
void				rrb(t_node **b, t_bench *bench);
void				rrr(t_node **a, t_node **b, t_bench *bench);

/* algos */
void				simple_sort(t_node **a, t_node **b, t_bench *bench);
void				medium_sort(t_node **a, t_node **b, t_bench *bench);
void				complex_sort(t_node **a, t_node **b, t_bench *bench);
void				adaptive_sort(t_node **a, t_node **b, t_bench *bench);
double				calculate_disorder(t_node *a);

/* strategy */
void				run_sort(t_node **a, t_node **b, t_flags *flags);

/* utils */
long				ft_atol(char *s);
void				test_char(char *s);
int					ft_isdigit(int c);
int					ft_strcmp(char *s1, char *s2);
char				**ft_split(char *s, char c);
char				*ft_strchr(char *s, int c);
int					count_splits(char **split);
int					is_number(char *c);
int					is_space(char *c);
int					is_add_subscribe(char *c);

/* error */
void				error_exit(void);
int					check_duplicates(int *tab, int size);

/* free */
void				free_stack(t_node **stack);
void				free_all(t_node **a, t_node **b);
void				free_split_args(char **new_av, int start, int total_ac,
						int old_ac);

#endif
