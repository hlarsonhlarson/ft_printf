/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:11:40 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/16 18:47:22 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	checkflag(char *format, size_t i, t_flag *flag)
{
	if ((format[i] != '+') && (format[i] != '-') && (format[i] != '#')
			&& (format[i] != '0') && (format[i] != ' '))
		return (i);
	while ((format[i] == '+') || (format[i] == '-') || (format[i] == '#')
			|| (format[i] == '0') || (format[i] == ' '))
	{
		if (format[i] == '+')
			flag->plus = 1;
		if (format[i] == '-')
			flag->minus = 1;
		if (format[i] == '#')
			flag->octotorp = 1;
		if (format[i] == '0')
			flag->zero = 1;
		if (format[i] == ' ')
			flag->space = 1;
		i++;
	}
	return (i);
}

size_t	checkwidth(char *format, size_t i, va_list ap, t_flag *flag)
{
	if (format[i] == '*')
	{
		flag->width = va_arg(ap, int);
		i++;
		return (i);
	}
	if (format[i] >= '0' && format[i] <= '9')
	{
		while (format[i] >= '0' && format[i] <= '9')
		{
			flag->width *= 10;
			flag->width += format[i] - '0';
			i++;
		}
	}
	return (i);
}

size_t	checkprecision(char *format, size_t i, va_list ap, t_flag *flag)
{
	if (format[i] != '.')
		return (i);
	i++;
	if (format[i] == '*')
	{
		flag->precision = va_arg(ap, int);
		i++;
		return (i);
	}
	flag->precision = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		flag->precision *= 10;
		flag->precision += format[i] - '0';
		i++;
	}
	return (i);
}

size_t	checksize(char *format, size_t i, t_flag *flag)
{
	if (format[i] == 'h' && format[i + 1] == 'h')
		flag->format = 1;
	if (format[i] == 'l' && format[i + 1] == 'l')
		flag->format = 2;
	if (format[i] == 'L')
		flag->format = 3;
	if (format[i] == 'h' && format[i + 1] != 'h')
		flag->format = 4;
	if (format[i] == 'l' && format[i + 1] != 'l')
		flag->format = 5;
	if (format[i] == 'z')
		flag->format = 6;
	if (format[i] == 'j')
		flag->format = 7;
	if (flag->format != 0)
		i++;
	if (flag->format == 1 || flag->format == 2)
		i++;
	return (i);
}

char	*checktype(char *format, size_t i, va_list ap, t_flag *flag)
{
	char	*d;

	if (format[i] == 'd' || format[i] == 'i')
		d = ft_int(format[i], flag, ap);
	if (format[i] == 'o')
		d = ft_octal(format[i], flag, ap);
	if (format[i] == 'u')
		d = ft_unsigned_int(format[i], flag, ap);
	if (format[i] == 'x' || format[i] == 'X')
		d = ft_hex(format[i], flag, ap);
	if (format[i] == 'f' || format[i] == 'F')
		d = ft_float(format[i], flag, ap);
	if (format[i] == 'c')
		d = ft_create_char(format[i], flag, ap);
	if (format[i] == 's')
		d = ft_create_str(format[i], flag, ap);
	if (format[i] == '%')
		d = ft_percent(format[i], flag);
	if (format[i] == 'p')
		d = ft_pointer(format[i], flag, ap);
	return (d);
}
