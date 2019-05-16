/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:16:04 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/13 16:27:42 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_help_with_precision(char **d, int k)
{
	char	*x;
	char	*c;
	char	*a;
	char	*y;

	c = *d;
	x = ft_strjoin(ft_strdup("0."), ft_strnew_zero(k));
	a = ft_strjoin(x, ft_strdup("1"));
	y = ft_long_sum_dot(c, a);
	ft_strdel(&c);
	*d = y;
	ft_strdel(&a);
}

static char		*ft_right_precision(char *c, int i)
{
	int		j;
	char	*d;
	int		k;

	k = i;
	d = ft_strnew(get_before_dot_float(c) + i + 2);
	j = 0;
	while (c[j] != '.')
	{
		d[j] = c[j];
		j++;
	}
	d[j] = c[j];
	while (i != -1)
	{
		j++;
		d[j] = c[j];
		i--;
	}
	if (c[j + 1] >= '5')
		ft_help_with_precision(&d, k);
	ft_strdel(&c);
	return (d);
}

static char		*ft_pow_long_x(long long e, unsigned long long k)
{
	char		*c;
	char		*d;
	char		*x;

	d = ft_strdup("0.0");
	while (k != 0)
	{
		if (k & 1)
		{
			if (e - 63 < 0)
				c = ft_long_pow_minus(-(e - 63));
			else
				c = ft_long_pow(e - 63);
			x = ft_long_sum_dot(d, c);
			ft_strdel(&c);
			ft_strdel(&d);
			d = x;
		}
		k = k >> 1;
		e++;
	}
	return (d);
}

static char		*ft_create_float(long double d, int i)
{
	char					*c;
	unsigned long long		k;
	int						s;
	long long				e;
	int						j;

	i--;
	u_q.ld = d;
	s = (u_q.x[1] & 0x8000) >> 15;
	e = (u_q.x[1] & 0x7FFF) - 16383;
	k = (u_q.x[0] & 0xffffffffffffffff);
	c = ft_pow_long_x(e, k);
	j = get_after_dot_float(c);
	if (i == j)
		c = ft_strjoin(c, ft_strdup("0"));
	if (i > j)
		c = ft_strjoin(c, ft_strnew_zero(i - j + 1));
	if (i < j)
		c = ft_right_precision(c, i);
	c = (s == 1) ? ft_strjoin(ft_strdup("-"), c) : c;
	return (c);
}

char			*ft_long_double(char a, t_flag *flag, va_list ap)
{
	double	d;
	int		i;

	flag->type = a;
	i = 6;
	d = va_arg(ap, long double);
	if (flag->precision != -1)
		i = flag->precision;
	return (ft_work_flag(ft_create_float(d, i), flag));
}
