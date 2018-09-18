/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:30:20 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 09:02:10 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "printf.h"
# include <stdint.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

typedef struct	s_print
{
	const char	*format;
	char		*f_copy;
	char		*f_org;
	va_list		args;
	int			len;
	size_t		i;
	long int	prec;
	long int	f_w;
	char		s_f;
	char		convert[6];
	char		a_f[2];
	char		*specifier;
	char		*converter;
	char		*argument;
}				t_print;

int				ft_printf(const char *format, ...);
int				checks(t_print *print);

t_print			*init(t_print *print);
t_print			*reinit(t_print *print);

t_print			*convert(t_print *print);
t_print			*field_width(t_print *print);
t_print			*precision(t_print *print);
t_print			*arguments(t_print *print);
t_print			*specifier(t_print *print);
t_print			*print_printf(t_print *print);

t_print			*handle_d(t_print *print);
t_print			*handle_s(t_print *print);
t_print			*handle_c(t_print *print);
t_print			*handle_u(t_print *print);
t_print			*handle_x(t_print *print);
t_print			*handle_o(t_print *print);
t_print			*handle_p(t_print *print);
t_print			*handle_ws(t_print *print);
t_print			*handle_other(t_print *print);
void			handle_wchar(wint_t c, t_print *print);
void			handle_gap(t_print *print, char c, int len, int update_len);

#endif
