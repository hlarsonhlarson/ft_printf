/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_flag_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 20:43:44 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/18 12:46:25 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_work_with_plus(char *c, t_flag *flag)
{
	if (flag->type == 'x' || flag->type == 'X' || flag->type == 'o')
		return (c);
	if (c[0] != '-' )//&& c[0] != '0')
		c = ft_strjoin(ft_strdup("+"), c);
	if (c[0] == '0' && flag->precision != -1 && flag->zero != 0)
		c = ft_strjoin(ft_strdup("+"), c);
	return (c);
}

char	*ft_work_with_space(char *c, t_flag *flag)
{
	char	*d;

	if (flag->type == 'x' || flag->type == 'X' || flag->type == 'o' || flag->type == '%')
		return (c);
	if (c[0] == '-' || c[0] == '+')
		return (c);
	d = ft_strnew(1);
	d[0] = ' ';
	return (ft_strjoin(d, c));
}

char	*ft_work_with_octotorp(char *c, t_flag *flag)
{
	char	*d;

	if (flag->type != 'x' && flag->type != 'X'
			&& flag->type != 'o' && flag->type != 'p')
		return (c);
	if (flag->type == 'o')
	{
		d = ft_strnew(1);
		d[0] = '0';
	}
	else if (flag->type != 'p')
	{
		d = ft_strnew(2);
		d[0] = '0';
		d[1] = (flag->type == 'X') ? 'X' : 'x';
	}
	else
		d = ft_strdup("0x");
	return (ft_strjoin(d, c));
}
