/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:35:19 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/11 20:12:13 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_k_ok(char **b, int k, int j)
{
	char	*c;

	c = *b;
	if (k == 0)
		return ;
	while (k != 0)
	{
		k = k * 10;
		c[j] = k / 2 + '0';
		j++;
		k = k % 2;
	}
}

void	ft_division(char **c, size_t i, int k, char *a)
{
	char	*b;
	int		j;

	j = 0;
	b = *c;
	while (a[i])
	{
		if (a[i] == '.')
		{
			b[j] = a[i];
			i++;
			j++;
		}
		k = k * 10 + a[i] - '0';
		if (k / 2 != 0)
		{
			b[j] = k / 2 + '0';
			k = k % 2;
		}
		else
			b[j] = '0';
		j++;
		i++;
	}
	is_k_ok(&b, k, j);
}

char	*ft_long_division(char *a)
{
	size_t	i;
	char	*b;
	int		k;
	int		j;

	i = 0;
	j = 0;
	k = 0;
	b = ft_strnew(ft_strlen(a) + 2);
	is_k_ok(&b, k, j);
	ft_division(&b, i, k, a);
	return (b);
}
