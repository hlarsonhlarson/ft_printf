/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:18:13 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/12 18:44:44 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static	int		sign(int k, int j)
{
	if (k == 1)
		return (j * (-1));
	else
		return (j);
}

static	int		isspace(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 || str[i] == 12 ||
			str[i] == 13 || str[i] == 11)
		i++;
	return (i);
}

int				ft_atoi(const char *nptr)
{
	size_t				i;
	unsigned long long	j;
	int					k;
	int					l;

	i = isspace(nptr) + 1;
	j = 0;
	k = 0;
	l = 0;
	if (nptr[i - 1] == '-')
		k = 1;
	else if (nptr[i - 1] != '+')
		i--;
	while (nptr[i] == '0')
		i++;
	while ((nptr[i] >= '0') && (nptr[i] <= '9') && nptr[i])
	{
		j = j * 10 + (nptr[i] - '0');
		l++;
		i++;
	}
	if (l > 19)
		return (-1 + k);
	return (sign(k, (int)(j)));
	return (0);
}
