/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:32:04 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 08:55:41 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <ctype.h>

t_print			*handle_c(t_print *print)
{
	wint_t		c;

	if (ft_strcmp(print->a_f, "l") == 0)
		c = (unsigned long)va_arg(print->args, unsigned long);
	else if (print->s_f == 'C')
		c = (wchar_t)va_arg(print->args, wint_t);
	else
		c = (char)va_arg(print->args, int);
	c = (wint_t)c;
	if (print->convert[3] == '0' && print->convert[0] != '-')
		handle_gap(print, '0', print->f_w - 1, 1);
	else if (print->convert[0] != '-')
		handle_gap(print, ' ', print->f_w - 1, 1);
	handle_wchar(c, print);
	if (print->convert[0] == '-')
		handle_gap(print, ' ', print->f_w - 1, 1);
	return (print);
}
