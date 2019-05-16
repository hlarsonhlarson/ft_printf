/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:35:19 by hlarson           #+#    #+#             */
/*   Updated: 2019/04/19 23:01:04 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_long_pow(long long n)
{
	char	*d;
	char	*l;

	if (n == 0)
		return (ft_strdup("1.0"));
	d = ft_strnew(3);
	d[0] = '1';
	d[1] = '.';
	d[2] = '0';
	while (n != 0)
	{
		l = ft_long_composition_dot("2", d);
		ft_strdel(&d);
		d = l;
		n--;
	}
	return (d);
}
