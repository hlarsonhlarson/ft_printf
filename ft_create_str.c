/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:11:40 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/13 19:06:15 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_creation_of_str(char *c, t_flag *flag)
{
	char	*d;
	size_t	i;
	size_t	j;

	if (c == NULL)
		return (ft_strdup("(null)"));
	d = ft_strdup(c);
	j = ft_strlen(d);
	if (flag->precision != -1 && j != 0)
	{
		i = flag->precision;
		while (i != j)
		{
			d[i] = '\0';
			i++;
		}
	}
	return (d);
}

char	*ft_create_str(char a, t_flag *flag, va_list ap)
{
	char	*c;

	flag->type = a;
	c = va_arg(ap, char *);
	return (ft_work_flag(ft_creation_of_str(c, flag), flag));
}
