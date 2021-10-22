/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshelob <cshelob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:07:15 by cshelob           #+#    #+#             */
/*   Updated: 2021/10/20 16:31:06 by cshelob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_type(char c, t_opt *option)
{
	option->type = (int)c;
	return (option->index + 1);
}

int	ft_parse(char *input, t_opt *option, va_list ap)
{
	int		cnt;
	int		*idx;

	cnt = 0;
	idx = &(option->index);
	if (!(ft_strchr(TYPE, input[*idx]) && input))
		return (-1);
	*idx = ft_parse_type(input[*idx], option);
	cnt += ft_conversion(option->type, ap);
	return (cnt);
}
