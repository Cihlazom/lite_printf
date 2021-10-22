/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshelob <cshelob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:05:36 by cshelob           #+#    #+#             */
/*   Updated: 2021/10/20 15:11:58 by cshelob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(int c, va_list ap)
{
	int		cnt;

	cnt = 0;
	if (c == 'c')
		cnt += ft_convert_char(va_arg(ap, int));
	else if (c == 's')
		cnt += ft_convert_str(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		cnt += ft_convert_int(va_arg(ap, int));
	else if (c == '%')
		cnt += ft_convert_percent();
	else if (c == 'u')
		cnt += ft_convert_unsigned(va_arg(ap, int));
	else if (c == 'x')
		cnt += ft_convert_hex(va_arg(ap, int), SMALLX);
	else if (c == 'X')
		cnt += ft_convert_hex(va_arg(ap, int), BIGX);
	else if (c == 'p')
		cnt += ft_convert_ptr(va_arg(ap, void *));
	return (cnt);
}
