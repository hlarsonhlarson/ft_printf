/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:42:38 by hlarson           #+#    #+#             */
/*   Updated: 2019/05/18 15:11:40 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct	s_flag
{
	int			minus;
	int			plus;
	int			space;
	int			format;
	int			octotorp;
	int			zero;
	int			width;
	int			precision;
	char		type;
	char		*value;
}				t_flag;

union
{
	double		fl;
	long long	x;
}				u_f;

union
{
	long double				ld;
	unsigned long long		x[2];
}				u_q;

char			*ft_strnew(size_t size);
void			ft_bzero(void *s, size_t len);
size_t			count_numbers(uintmax_t n, int k);
void			ft_putstr(char const *c);
void			ft_putchar(char c);
char			*ft_int(char a, t_flag *flag, va_list ap);
char			*create_until_percent(char *format, size_t *i, size_t k);
char			*ft_strjoin(char *a, char *b);
void			ft_strdel(char **as);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *c);
char			*ft_unsigned_int(char a, t_flag *flag, va_list ap);
char			*ft_octal(char a, t_flag *flag, va_list ap);
char			*ft_hex(char a, t_flag *flag, va_list ap);
char			*ft_work_flag(char *c, t_flag *flag);
int				ft_pow(int n);
char			*ft_float(char a, t_flag *flag, va_list ap);
char			*ft_long_long(unsigned long long d);
char			*ft_float_precision(int i, double d);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strnew_zero(size_t size);
char			*ft_strnew_one(size_t size);
void			ft_zero(void *s, size_t len);
void			ft_one(void *s, size_t len);
char			*ft_strrjoin(char *a, char *b);
char			*ft_long_sum(char *a, char *b);
char			*ft_long_composition(char *a, char *b);
char			*ft_long_pow(long long n);
char			*ft_long_sum_dot(char *a, char *b);
char			*ft_long_composition_dot(char *a, char *b);
char			*ft_long_division(char *a);
char			*ft_long_pow_minus(long long n);
char			*ft_long_double(char a, t_flag *flag, va_list ap);
int				get_before_dot_float(char *c);
int				get_after_dot_float(char *c);
int				ft_atoi(const char *nptr);
char			*create_after_percent(char *c, size_t i, size_t j);
char			*ft_work_with_plus(char *c, t_flag *flag);
char			*ft_work_with_space(char *c, t_flag *flag);
char			*ft_work_with_octotorp(char *c, t_flag *flag);
char			*ft_long_double(char a, t_flag *flag, va_list ap);
char			*ft_create_char(char a, t_flag *flag, va_list ap);
char			*ft_create_str(char a, t_flag *flag, va_list ap);
char			*ft_percent(char a, t_flag *flag);
char			*ft_pointer(char a, t_flag *flag, va_list ap);
size_t			checkflag (char *format, size_t i, t_flag *flag);
size_t			checkwidth(char *format, size_t i, va_list ap, t_flag *flag);
size_t			checkprecision(char *format, size_t i,
		va_list ap, t_flag *flag);
size_t			checksize(char *format, size_t i, t_flag *flag);
char			*checktype(char *format, size_t i, va_list ap, t_flag *flag);
int				ft_printf(char *format, ...);
void			*ft_memmove(void *dest, const void *src, size_t n);

#endif
