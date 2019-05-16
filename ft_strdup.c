/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:20:01 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/06 16:50:05 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *b)
{
	size_t		i;

	i = 0;
	while (b[i])
		i++;
	return (i);
}

char			*ft_strdup(const char *c)
{
	char		*a;
	size_t		i;

	a = (char *)malloc(sizeof(*c) * (ft_strlen(c) + 1));
	if (!a)
		return (NULL);
	i = 0;
	while (c[i])
	{
		a[i] = c[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
