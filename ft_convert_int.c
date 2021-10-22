/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshelob <cshelob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:05:47 by cshelob           #+#    #+#             */
/*   Updated: 2021/10/20 16:38:34 by cshelob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_numsize(int n, int base)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	else
	{
		if (n < 0 && n != -2147483648)
			n *= -1;
		while (n > 0 || n == -2147483648)
		{
			n /= base;
			if (n < 0)
				n *= -1;
			size++;
		}
	}
	return (size);
}

static void	ft_put_left(int minus, int n)
{
	if (minus == 1 && n != -2147483648)
	{
		ft_putchar('-');
		n *= -1;
	}
	ft_put_int(n);
}

int	ft_convert_int(int n)
{
	int		num_size;
	int		minus;

	minus = 0;
	if (n < 0)
		minus = 1;
	num_size = ft_get_numsize(n, DEC);
	ft_put_left(minus, n);
	return (num_size + minus);
}
