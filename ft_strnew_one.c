/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:11:40 by hlarson           #+#    #+#             */
/*   Updated: 2019/03/26 19:33:34 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew_one(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str)
		ft_one(str, size + 1);
	else
		return (NULL);
	return (str);
}
