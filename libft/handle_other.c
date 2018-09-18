/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:34:19 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 08:56:49 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

static t_print	*display_percent(t_print *print)
{
	if (print->convert[3] == '0' && print->prec <= 0 && !print->convert[0])
	{
		print->prec = print->f_w;
		print->f_w = 0;
	}
	if (print->convert[0] != '-')
		handle_gap(print, ' ', print->f_w - 1, 1);
	if (print->convert[3] == '0')
		handle_gap(print, '0', print->prec - 1, 1);
	write(1, "%", 1);
	if (print->convert[0] == '-')
		handle_gap(print, ' ', print->f_w - 1, 1);
	print->len++;
	return (print);
}

t_print			*handle_other(t_print *print)
{
	if (print->f_org[print->i] == '%')
	{
		display_percent(print);
		return (print);
	}
	if (print->convert[3] == '0' && print->prec <= 0 && !print->convert[0])
	{
		print->prec = print->f_w;
		print->f_w = 0;
	}
	if (print->convert[0] != '-')
		handle_gap(print, ' ', print->f_w - 1, 1);
	if (print->convert[3] == '0')
		handle_gap(print, '0', print->prec - 1, 1);
	write(1, &print->f_copy[print->i], 1);
	if (print->convert[0] == '-')
		handle_gap(print, ' ', print->f_w - 1, 1);
	print->len++;
	return (print);
}
