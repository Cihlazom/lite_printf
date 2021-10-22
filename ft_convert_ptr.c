/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshelob <cshelob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:05:55 by cshelob           #+#    #+#             */
/*   Updated: 2021/10/20 16:29:28 by cshelob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_llnumsize(unsigned long long n, int base)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	while (n > 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

static void	ft_put_ptr(unsigned long long n)
{
	char	ch;

	if (n >= HEX)
		ft_put_ptr(n / HEX);
	ch = n % HEX;
	if (ch > 9)
		ch += 'a' - 10;
	else
		ch += '0';
	write(FD, &ch, 1);
}

static void	ft_put_ptr_left(unsigned long long n, int num_size)
{
	ft_putstr_fd("0x", FD);
	if (num_size)
		ft_put_ptr(n);
}

int	ft_convert_ptr(void *ptr)
{
	unsigned long long	n;
	int					num_size;

	n = (unsigned long long)ptr;
	num_size = ft_get_llnumsize(n, HEX);
	ft_put_ptr_left(n, num_size);
	return (num_size + 2);
}
