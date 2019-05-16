/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:39:17 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/16 20:13:33 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*a;
	char		*b;

	if (dest == src)
		return (dest);
	a = (char *)src;
	b = (char*)dest;
	if (a < b)
	{
		i = n;
		while (i-- != 0)
			b[i] = a[i];
	}
	else
	{
		i = 0;
		while (i != n)
		{
			b[i] = a[i];
			i++;
		}
	}
	return (b);
}
