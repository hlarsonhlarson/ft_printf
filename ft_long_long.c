/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:07:52 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/11 20:13:08 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ten_count_numbers(unsigned long long n, int k)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= k;
		i++;
	}
	return (i);
}

char	*ft_long_long(unsigned long long d)
{
	char	*c;
	size_t	i;
	char	*k;

	c = "0123456789";
	i = ten_count_numbers(d, 10);
	k = ft_strnew(i);
	while (d)
	{
		k[i - 1] = c[d % 10];
		d /= 10;
		i--;
	}
	return (k);
}
