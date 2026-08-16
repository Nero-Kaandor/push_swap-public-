/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:34:33 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 12:22:54 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

// Enumeration of available sorting strategies
typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}				t_strategy;

// Structure storing parsed command-line flags
typedef struct s_flags
{
	t_strategy	strategy;
	int			isbench;
}				t_flags;

// Parses command-line flags and initializes the flags structure
void			init_flags(t_flags *flags);
int				parse_flags(int ac, char **av, t_flags *flags);

#endif
