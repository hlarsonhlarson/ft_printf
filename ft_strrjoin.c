/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:16:04 by hlarson           #+#    #+#             */
/*   Updated: 2019/03/26 17:10:58 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_strrjoin(char *a, char *b)
{
	char	*c;
	char	*d;
	char	*x;
	size_t	i;

	d = a;
	x = b;
	i = 0;
	c = ft_strnew(ft_strlen(d) + ft_strlen(x));
	while (*d)
		c[i++] = *d++;
	while (*x)
		c[i++] = *x++;
	ft_strdel(&a);
	return (c);
}
