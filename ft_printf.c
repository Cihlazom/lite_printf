/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshelob <cshelob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:07:18 by cshelob           #+#    #+#             */
/*   Updated: 2021/10/22 15:02:56 by cshelob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_option(t_opt *option, int *idx)
{
	option->type = 0;
	*idx += 1;
}

int	ft_control(va_list ap, t_opt *option, char *input)
{
	int		ret;
	int		cnt;
	int		*idx;

	ret = 0;
	cnt = 0;
	idx = &(option->index);
	*idx = 0;
	while (input[*idx] != '\0')
	{
		while (input[*idx] != '%' && input[*idx] != '\0')
		{
			ret += ft_putchar(input[*idx]);
			*idx += 1;
		}
		if (input[*idx] == '%' && input[*idx] != '\0')
		{
			ft_reset_option(option, idx);
			cnt = ft_parse(input, option, ap);
			if (cnt == -1)
				return (ret = -1);
			ret += cnt;
		}
	}
	return (ret);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	t_opt	*option;
	int		ret;

	va_start(ap, input);
	option = (t_opt *)malloc(sizeof(t_opt));
	if (!option)
		return (-1);
	ret = ft_control(ap, option, (char *)input);
	free(option);
	va_end(ap);
	return (ret);
}
