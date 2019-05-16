/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:11:40 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/13 16:22:07 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_creation_of_char(char c)
{
	char	*d;

	d = ft_strnew(1);
	d[0] = c;
	return (d);
}

char	*ft_create_char(char a, t_flag *flag, va_list ap)
{
	char	c;

	flag->type = a;
	c = (char)va_arg(ap, int);
	return (ft_work_flag(ft_creation_of_char(c), flag));
}
