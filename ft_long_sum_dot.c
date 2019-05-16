/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:35:19 by hlarson           #+#    #+#             */
/*   Updated: 2019/04/19 20:55:34 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_dot(char *a)
{
	int		i;

	i = 0;
	while (a[i] != '.')
		i++;
	return (i);
}

static char		*get_with_dot(char *a)
{
	char	*x;
	char	*y;
	int		i;
	int		j;

	j = 0;
	i = get_dot(a);
	x = ft_strnew(i);
	while (i != 0)
	{
		x[i - 1] = a[i - 1];
		i--;
	}
	i = get_dot(a) + 1;
	y = ft_strnew(ft_strlen(a) - i);
	while (a[i])
	{
		y[j] = a[i];
		i++;
		j++;
	}
	return (ft_strjoin(x, y));
}

static int		get_number(char *a, char *b, char **x, char **y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (a[i] != '.')
		i++;
	i = ft_strlen(a) - i;
	while (b[j] != '.')
		j++;
	j = ft_strlen(b) - j;
	if (i > j)
		*y = ft_strjoin(*y, ft_strnew_zero(i - j));
	else
		*x = ft_strjoin(*x, ft_strnew_zero(j - i));
	return ((i > j) ? i : j);
}

static char		*get_all(char *z, int i)
{
	char	*x;
	int		k;

	k = ft_strlen(z);
	x = ft_strnew(ft_strlen(z) + 1);
	while (i != 0)
	{
		x[k + 1] = z[k];
		k--;
		i--;
	}
	x[k + 1] = '.';
	while (k != -1)
	{
		x[k] = z[k];
		k--;
	}
	return (x);
}

char			*ft_long_sum_dot(char *a, char *b)
{
	char	*x;
	char	*y;
	char	*z;
	char	*d;
	int		i;

	x = get_with_dot(a);
	y = get_with_dot(b);
	i = get_number(a, b, &x, &y);
	z = ft_long_sum(x, y);
	ft_strdel(&x);
	ft_strdel(&y);
	d = get_all(z, i);
	ft_strdel(&z);
	return (d);
}
