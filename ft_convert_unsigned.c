/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshelob <cshelob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:07:11 by cshelob           #+#    #+#             */
/*   Updated: 2021/10/20 16:30:55 by cshelob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_lnumsize(unsigned int n, int base)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	else
	{
		while (n > 0)
		{
			n /= base;
			size++;
		}
	}
	return (size);
}

void	ft_putl_left(unsigned int n, int conversion)
{
	int	base;

	if (conversion == SMALLX || conversion == BIGX)
		base = HEX;
	else
		base = DEC;
	ft_put_uint(n, base, conversion);
}

int	ft_convert_unsigned(unsigned int n)
{
	int		num_size;

	num_size = ft_get_lnumsize(n, DEC);
	ft_putl_left(n, DEC);
	return (num_size);
}
