/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:11:40 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/18 19:04:42 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_pointer(uintmax_t n)
{
	char	*c;
	size_t	i;
	char	*x;

	c = "0123456789abcdef";
	i = count_numbers(n, 16) - 1;
	if (n == 0)
		return (ft_strdup("0"));
	x = ft_strnew(i + 1);
	while (n)
	{
		x[i] = c[n % 16];
		n /= 16;
		i--;
	}
	return (x);
}

char	*ft_pointer(char a, t_flag *flag, va_list ap)
{
	uintmax_t	d;

	flag->type = a;
	flag->octotorp = 1;
	d = (uintmax_t)va_arg(ap, unsigned long long);
	return (ft_work_flag(hex_pointer(d), flag));
}
