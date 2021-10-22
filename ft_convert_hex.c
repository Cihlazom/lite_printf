/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshelob <cshelob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:05:44 by cshelob           #+#    #+#             */
/*   Updated: 2021/10/20 16:29:53 by cshelob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_hex(unsigned int n, int conversion)
{
	int		num_size;

	num_size = ft_get_lnumsize(n, HEX);
	ft_putl_left(n, conversion);
	return (num_size);
}
