/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshelob <cshelob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:07:22 by cshelob           #+#    #+#             */
/*   Updated: 2021/10/20 16:45:59 by cshelob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"
# define TYPE "cspdiuxX%"
# define DEC 10
# define HEX 16
# define FD 1
# define SMALLX 1
# define BIGX 2

typedef struct s_opt
{
	int		index;
	int		type;
}				t_opt;

int		ft_printf(const char *input, ...);
int		ft_putchar(char s);
void	ft_put_int(int n);
void	ft_put_uint(unsigned int n, int base, int conversion);

int		ft_parse_type(char c, t_opt *option);
int		ft_parse(char *input, t_opt *option, va_list ap);

int		ft_conversion(int c, va_list ap);
int		ft_get_numsize(int n, int base);
int		ft_get_lnumsize(unsigned int n, int base);
void	ft_putl_left(unsigned int n, int base);
void	ft_putl_right(t_opt *option, unsigned int n, int num_size, int base);
int		ft_convert_char(char c);
int		ft_convert_str(char *str);
int		ft_convert_int(int n);
int		ft_convert_percent(void);
int		ft_convert_unsigned(unsigned int n);
int		ft_convert_hex(unsigned int n, int conversion);
int		ft_convert_ptr(void *ptr);

#endif
