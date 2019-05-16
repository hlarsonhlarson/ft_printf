/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:16:04 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/11 20:02:01 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_strjoin(char *a, char *b)
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
	ft_strdel(&b);
	return (c);
}
