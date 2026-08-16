/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_printf_bench.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catsin-k <catsin-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:30:37 by catsin-k          #+#    #+#             */
/*   Updated: 2026/02/10 11:51:32 by catsin-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_putstr_bench(char *str)
{
	int	i;

	if (!str)
		return (write(2, "(null)", 6));
	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (i);
}

static int	ft_putnbr_bench(int n)
{
	int	res;

	res = 0;
	if (n == -2147483648)
		return (write(2, "-2147483648", 11));
	if (n < 0)
	{
		res += write(2, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		res += ft_putnbr_bench(n / 10);
		res += ft_putnbr_bench(n % 10);
	}
	else
		res += write(2, &"0123456789"[n], 1);
	return (res);
}

static int	ft_putchar_bench(char c)
{
	return (write(2, &c, 1));
}

static int	ft_formats_bench(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_bench(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr_bench(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_bench(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_bench(va_arg(args, unsigned int)));
	if (c == '%')
		return (write(2, "%", 1));
	return (0);
}

int	ft_printf_bench(char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_formats_bench(args, format[i + 1]);
			i++;
		}
		else
			count += write(2, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
