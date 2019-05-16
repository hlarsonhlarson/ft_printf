/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:38:56 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/11 20:36:35 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ten_count_numbers(unsigned long long n, int k)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= k;
		i++;
	}
	i++;
	return (i);
}

static char			*ft_ten(unsigned long long d)
{
	char	*c;
	size_t	i;
	char	*k;

	c = "0123456789";
	i = ten_count_numbers(d, 10) - 1;
	k = ft_strnew(i);
	i--;
	while (d)
	{
		k[i] = c[d % 10];
		d /= 10;
		i--;
	}
	return (k);
}

char				*ft_unsigned_int(char a, t_flag *flag, va_list ap)
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
	return ((ft_work_flag(ft_ten(d), flag)));
}
