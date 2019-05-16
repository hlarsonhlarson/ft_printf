/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:38:56 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/12 18:53:44 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_until_percent(char *format, size_t *i, size_t k)
{
	char	*c;
	size_t	j;
	size_t	l;

	l = 0;
	j = *i;
	c = ft_strnew(j);
	j = k;
	*i = *i + 1;
	while (format[j] != '%')
	{
		c[l] = format[j];
		j++;
		l++;
	}
	return (c);
}
