/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:40:48 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/11 19:41:29 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		count_numbers(unsigned long long n, int k)
{
	size_t		i;

	i = 0;
	while (n)
	{
		i++;
		n = n / k;
	}
	return (i);
}