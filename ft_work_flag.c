/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:16:04 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/18 15:22:58 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_work_with_zero(char *c, t_flag *flag)
{
	char	*d;
	size_t	j;

	j = 0;
	if (c[0] == '-')
	{
		flag->space = 0;
		flag->plus = 0;
		j = 1;
	}
	if (flag->precision != -1
			|| flag->minus == 1 || (flag->width <= (int)ft_strlen(c) + flag->plus + flag->space + 2 * flag->octotorp))
		return (c);
	c[0] = (j == 1) ? '0' : c[0];
	if (j == 1)
		d = ft_strnew_zero(flag->width - ft_strlen(c)
				- (2 * flag->octotorp));
	else
		d = ft_strnew_zero(flag->width - ft_strlen(c)
				- (2 * flag->octotorp) - flag->space - flag->plus);
	d[0] = (j == 1) ? '-' : d[0];
	c = ft_strjoin(d, c);
	return (c);
}

char	*ft_work_with_minus(char *c, t_flag *flag)
{
	char	*d;
	size_t	i;

	i = 0;
	if (((int)flag->width - (int)ft_strlen(c)) > 0)
	{
		d = ft_strnew(flag->width - ft_strlen(c));
		while (i < flag->width - ft_strlen(c))
		{
			d[i] = ' ';
			i++;
		}
		c = ft_strjoin(c, d);
	}
	return (c);
}

char	*ft_work_with_precision_not_float(char *c, t_flag *flag)
{
	char	*d;

	if (flag->type == 'f' || flag->type == 'e' || flag->type == 'E' || flag->type == 's' || flag->type == 'c')
		return (c);
	if ((int)((int)flag->precision - (int)ft_strlen(c)) >= 0)
		d = (c[0] == '-') ? ft_strnew_zero(flag->precision - ft_strlen(c) + 2) : ft_strnew_zero(flag->precision - ft_strlen(c));
	else
		return (c);
	if (c[0] == '-')
	{
		d[0] = '-';
		ft_memmove(c, c + 1, ft_strlen(c) - 1);
		c[ft_strlen(c) - 1] = '\0';
	}
	c = ft_strjoin(d, c);
	return (c);
}

char	*ft_work_with_width(char *c, t_flag *flag)
{
	char	*d;
	size_t	i;

	if (flag->width == 0
			|| (size_t)flag->width < ft_strlen(c))
		return (c);
	i = 0;
	d = ft_strnew(flag->width - ft_strlen(c));
	while (i < (size_t)flag->width - ft_strlen(c))
	{
		d[i] = ' ';
		i++;
	}
	c = ft_strjoin(d, c);
	return (c);
}

char	*ft_work_flag(char *c, t_flag *flag)
{
	if (flag->precision != -1)
		c = ft_work_with_precision_not_float(c, flag);
	//printf("1 %s\n", c);
	if (flag->zero == 1)
		c = ft_work_with_zero(c, flag);
	//printf("2 %s\n", c);
	if (flag->plus == 1)
		c = ft_work_with_plus(c, flag);
	//printf("3 %s\n", c);
	if (flag->space == 1)
		c = ft_work_with_space(c, flag);
	//printf("4 %s\n", c);
	if (flag->octotorp == 1)
		c = ft_work_with_octotorp(c, flag);
	//printf("5 %s\n", c);
	if (flag->minus == 1)
		c = ft_work_with_minus(c, flag);
	else
		c = ft_work_with_width(c, flag);
	return (c);
}
