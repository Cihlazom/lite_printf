/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshelob <cshelob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:07:08 by cshelob           #+#    #+#             */
/*   Updated: 2021/10/20 16:30:38 by cshelob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_str(char *str)
{
	int		len;
	int		i;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (len);
}
