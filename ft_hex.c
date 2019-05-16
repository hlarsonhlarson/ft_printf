/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:39:02 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/13 19:01:33 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex(unsigned long long n, char a, t_flag *flag)
{
	char				*c;
	size_t				i;
	char				*x;

	if (a == 'X')
		c = "0123456789ABCDEF";
	if (a == 'x')
		c = "0123456789abcdef";
	if (flag->precision == 0)
	{
		flag->octotorp = 0;
		return (ft_strdup(""));
	}
	if (n == 0)
	{
		flag->octotorp = 0;
		return (ft_strdup("0"));
	}
	i = count_numbers(n, 16) - 1;
	x = ft_strnew(i + 1);
	while (n)
	{
		x[i] = c[n % 16];
		n /= 16;
		i--;
	}
	return (x);
}

char	*ft_hex(char a, t_flag *flag, va_list ap)
{
	unsigned long long	d;

	flag->type = a;
	if (flag->format == 0)
		d = (unsigned long long)va_arg(ap, unsigned int);
	if (flag->format == 1)
		d = (unsigned long long)((unsigned char)va_arg(ap, unsigned int));
	if (flag->format == 2)
		d = (unsigned long long)va_arg(ap, unsigned long long);
	if (flag->format == 4)
		d = (unsigned long long)((unsigned short)va_arg(ap, unsigned int));
	if (flag->format == 5)
		d = (unsigned long long)va_arg(ap, unsigned long);
	if (flag->format == 6)
		d = (unsigned long long)va_arg(ap, size_t);
	return ((ft_work_flag(hex(d, a, flag), flag)));
}
