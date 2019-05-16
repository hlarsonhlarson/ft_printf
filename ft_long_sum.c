/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:35:19 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/11 20:26:42 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*new(char *a)
{
	char	*d;
	size_t	i;
	size_t	k;

	k = ft_strlen(a);
	d = ft_strnew_zero(k + 1);
	i = 0;
	while (i != k)
	{
		d[i + 1] = a[i];
		i++;
	}
	ft_strdel(&a);
	return (d);
}

static char	*a_change(char *a, size_t i, size_t j, size_t k)
{
	if ((long long)i - 2 < 0)
	{
		a = new(a);
		a[0] = j + '0';
		a[1] = a[1] + k - j * 10;
	}
	else
	{
		a[i - 2] = a[i - 2] + j;
		a[i - 1] = a[i - 1] + k - j * 10;
	}
	return (a);
}

static char	*string_long_sum(char *a, char *b, size_t i)
{
	size_t		j;
	size_t		k;
	char		*c;
	char		*d;

	d = ft_strrjoin(ft_strnew_zero(ft_strlen(a) - ft_strlen(b)), b);
	c = ft_strnew_zero(i);
	while (i != 0)
	{
		k = 0;
		j = 0;
		k = a[i - 1] + d[i - 1] - '0' - '0';
		if ((j = k / 10 > 0))
			c = a_change(c, i, j, k);
		else
			c[i - 1] = c[i - 1] + k;
		if ((j = (c[i - 1] - '0') / 10 > 0))
		{
			k = 0;
			c = a_change(c, i, j, k);
		}
		i--;
	}
	free(d);
	return (c);
}

char		*ft_long_sum(char *a, char *b)
{
	char	*d;

	if (ft_strlen(a) >= ft_strlen(b))
		d = string_long_sum(a, b, ft_strlen(a));
	else
		d = string_long_sum(b, a, ft_strlen(b));
	return (d);
}
