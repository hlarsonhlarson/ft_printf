/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_includes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:08:25 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/22 20:13:47 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INCLUDES_H
# define FT_INCLUDES_H

typedef struct				s_flag
{
	int						minus;
	int						plus;
	int						space;
	int						format;
	int						octotorp;
	int						zero;
	int						width;
	int						precision;
	char					type;
	char					*value;
}							t_flag;

union
{
	double					fl;
	long long				x;
}							u_f;

union
{
	long double				ld;
	unsigned long long		x[2];
}							u_q;

#endif
