/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:35:19 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/11 20:17:37 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*small_string_long_composition(char *a, char b, size_t i)
{
	char	*d;
	char	*c;
	char	*l;
	int		k;

	d = ft_strnew(0);
	d = ft_strrjoin(d, "0");
	while (i < ft_strlen(a))
	{
		c = ft_strnew(2);
		if ((k = (a[i] - '0') * (b - '0')) / 10 > 0)
		{
			c[0] = k / 10 + '0';
			c[1] = k % 10 + '0';
		}
		else
			c[0] = k % 10 + '0';
		c = ft_strjoin(c, ft_strnew_zero(ft_strlen(a) - i - 1));
		l = ft_long_sum(d, c);
		ft_strdel(&d);
		ft_strdel(&c);
		d = l;
		i++;
	}
	return (d);
}

char		*ft_long_composition(char *a, char *b)
{
	size_t	i;
	char	*d;
	char	*c;
	char	*l;

	i = 0;
	d = ft_strnew(0);
	d = ft_strrjoin(d, "0");
	while (i < ft_strlen(b))
	{
		c = ft_strjoin(small_string_long_composition(a, b[i], 0),
						ft_strnew_zero(ft_strlen(b) - i - 1));
		l = ft_long_sum(d, c);
		ft_strdel(&d);
		ft_strdel(&c);
		d = l;
		i++;
	}
	return (d);
}
