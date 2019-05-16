/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_after_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:46:32 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/13 17:03:30 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_after_percent(char *c, size_t i, size_t j)
{
	char	*d;
	size_t	k;

	k = 0;
	d = ft_strnew(i - j);
	while (j != i)
	{
		d[k] = c[j];
		j++;
		k++;
	}
	return (d);
}
