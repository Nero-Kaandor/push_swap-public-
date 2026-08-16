# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 10:38:44 by catsin-k          #+#    #+#              #
#    Updated: 2026/02/10 12:05:09 by catsin-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

SRCS	= \
	main.c \
	\
	parse_flags.c \
	parse_args.c \
	parse_args_utils.c \
	\
	stack_build.c \
	stack_utils.c \
	stack_ops_push.c \
	stack_ops_swap.c \
	stack_ops_rotate.c \
	stack_ops_reverse_rotate.c \
	\
	algo_simple.c \
	algo_medium.c \
	algo_complex.c \
	algo_adaptive.c \
	\
	parse_choose_algo.c \
	\
	bench.c \
	\
	ft_utils.c \
	ft_split.c \
	bench_printf_bench.c \
	bench_printf_bench_utils.c \
	\
	error.c \
	cleanup.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
