/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:41:19 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/18 15:23:17 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_null_flag(t_flag *flag)
{
	flag->width = 0;
	flag->precision = -1;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->octotorp = 0;
	flag->type = 0;
	flag->format = 0;
}

size_t	help(size_t i, char *format, va_list ap, t_flag *flag)
{
	i = checkflag(format, i, flag);
	i = checkwidth(format, i, ap, flag);
	i = checkprecision(format, i, ap, flag);
	i = checksize(format, i, flag);
	return (i);
}

int		help_1(char **c, va_list ap)
{
	char	*a;
	int		k;

	a = *c;
	k = ft_strlen(a);
	write(1, a, k);
	ft_strdel(c);
	va_end(ap);
	return (k);
}

int		ft_printf(char *format, ...)
{
	va_list		ap;
	size_t		i;
	size_t		j;
	char		*c;
	t_flag		flag;

	va_start(ap, format);
	i = 0;
	j = 0;
	c = ft_strdup("");
	while (format[i])
	{
		if (format[i] == '%')
		{
			make_null_flag(&flag);
			c = ft_strjoin(c, create_until_percent(format, &i, j));
			i = help(i, format, ap, &flag);
			c = ft_strjoin(c, checktype(format, i, ap, &flag));
			i++;
			j = i;
		}
		i = (format[i] == '%') ? i : i + 1;
	}
	c = (j < i) ? ft_strjoin(c, create_after_percent(format, i, j)) : c;
	return (help_1(&c, ap));
}
/*
int		main()
{
	printf("\\!/%0#2hhx\\!/\n", 1892178697);
	ft_printf("\\!/%0#2hhx\\!/\n", 1892178697);
	return (0);
}*/
