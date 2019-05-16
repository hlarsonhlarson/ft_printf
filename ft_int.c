/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:38:56 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/16 18:47:49 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ten_count_numbers(intmax_t n, int k)
{
	int		i;

	i = 0;
	while (n)
	{
		n /= k;
		i++;
	}
	i++;
	return (i);
}

char				*ft_ten(intmax_t d, t_flag *flag)
{
	char	*c;
	int		i;
	char	*k;
	size_t	j;

	if (flag->precision == 0)
		return (ft_strdup(""));
	if (d == 0)
		return (ft_strdup("0"));
	c = "0123456789";
	j = 0;
	i = ten_count_numbers(d, 10) - 1;
//	if ((int)i > flag->precision && flag->precision != -1)
//		i = flag->precision;
	(d < 0) ? j++ : j;
	d = (d < 0) ? d * (-1) : d;
	k = ft_strnew(i + j);
	(d < 0) ? i : i--;
	while (i != -1)
	{
		k[i + j] = c[d % 10];
		d /= 10;
		i--;
	}
	k[0] = (j == 1) ? '-' : k[0];
	return (k);
}

char				*ft_int(char a, t_flag *flag, va_list ap)
{
	intmax_t	d;

	flag->type = a;
	if (flag->format == 0)
		d = (intmax_t)va_arg(ap, int);
	if (flag->format == 1)
		d = (intmax_t)((char)va_arg(ap, int));
	if (flag->format == 2)
		d = (intmax_t)va_arg(ap, long long);
	if (flag->format == 4)
		d = (intmax_t)((short)va_arg(ap, int));
	if (flag->format == 5)
		d = (intmax_t)va_arg(ap, long);
	if (flag->format == 6)
		d = (intmax_t)va_arg(ap, size_t);
	if (flag->format == 7)
		d = (intmax_t)va_arg(ap, intmax_t);
	return (ft_work_flag(ft_ten(d, flag), flag));
}
