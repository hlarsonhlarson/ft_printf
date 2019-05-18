/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:38:56 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/18 19:17:45 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ten_count_numbers(uintmax_t n, int k)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n /= k;
		i++;
	}
	i++;
	return (i);
}

static char			*ft_ten(uintmax_t d, t_flag *flag)
{
	char	*c;
	int		i;
	char	*k;

	if (flag->precision == 0)
		return (ft_strdup(""));
	if (d == 0)
		return (ft_strdup("0"));
	c = "0123456789";
	i = ten_count_numbers(d, 10) - 2;
	k = ft_strnew(i + 1);
	while (i != -1)
	{
		k[i] = c[d % 10];
		d /= 10;
		i--;
	}
	return (k);
}

char				*ft_unsigned_int(char a, t_flag *flag, va_list ap)
{
	uintmax_t	d;

	flag->type = a;
	if (flag->format == 0)
		d = (uintmax_t)va_arg(ap, unsigned int);
	if (flag->format == 1)
		d = (uintmax_t)((unsigned char)va_arg(ap, unsigned int));
	if (flag->format == 2)
		d = (uintmax_t)va_arg(ap, unsigned long long);
	if (flag->format == 4)
		d = (uintmax_t)((unsigned short)va_arg(ap, unsigned int));
	if (flag->format == 5)
		d = (uintmax_t)va_arg(ap, unsigned long);
	if (flag->format == 6)
		d = (uintmax_t)va_arg(ap, size_t);
	if (flag->format == 7)
		d = (uintmax_t)va_arg(ap, uintmax_t);
	return (ft_work_flag(ft_ten(d, flag), flag));
}
