/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:13:37 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/18 19:14:09 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*octal(uintmax_t n, t_flag *flag)
{
	char		*c;
	size_t		i;
	char		*d;

	if (flag->precision == 0)
		return (ft_strdup(""));
	c = "01234567";
	i = count_numbers(n, 8) - 1;
	if (n == 0)
		flag->octotorp = 0;
	d = ft_strnew(i + 1);
	if (n == 0)
		return (ft_strdup("0"));
	while (n)
	{
		d[i] = c[n % 8];
		n /= 8;
		i--;
	}
	return (d);
}

char	*ft_octal(char a, t_flag *flag, va_list ap)
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
	return (ft_work_flag(octal(d, flag), flag));
}
