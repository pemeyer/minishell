/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:35:50 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 08:57:32 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <limits.h>

static uintmax_t	get_num(t_print *print)
{
	uintmax_t	num;

	if (print->s_f == 'U')
		num = (unsigned long)(va_arg(print->args, unsigned long int));
	else if (ft_strcmp(print->a_f, "hh") == 0)
		num = (unsigned char)(va_arg(print->args, unsigned int));
	else if (ft_strcmp(print->a_f, "h") == 0)
		num = (unsigned short)(va_arg(print->args, unsigned int));
	else if (ft_strcmp(print->a_f, "ll") == 0)
		num = (unsigned long long)(va_arg(print->args, unsigned long long int));
	else if (ft_strcmp(print->a_f, "l") == 0)
		num = (unsigned long)(va_arg(print->args, unsigned long int));
	else if (ft_strcmp(print->a_f, "j") == 0)
		num = (uintmax_t)(va_arg(print->args, uintmax_t));
	else if (ft_strcmp(print->a_f, "z") == 0)
		num = (size_t)(va_arg(print->args, size_t));
	else
		num = (unsigned int)(va_arg(print->args, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static int			get_tens(uintmax_t num)
{
	int tens;

	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static t_print		*do_u(t_print *print, uintmax_t num, int num_width,
		int left)
{
	int			not_blank;

	not_blank = num_width;
	if (num_width <= print->prec)
		not_blank = print->prec;
	print->len += (not_blank <= print->f_w) ? print->f_w : not_blank;
	if (!left)
		handle_gap(print, ' ', print->f_w - not_blank, 0);
	handle_gap(print, '0', print->prec - num_width, 0);
	ft_putnbrmax_fd(num, 1);
	if (left)
		handle_gap(print, ' ', print->f_w - not_blank, 0);
	return (print);
}

t_print				*handle_u(t_print *print)
{
	uintmax_t	num;
	int			num_width;
	int			left;

	left = 0;
	num = get_num(print);
	if (num == 0 && print->prec == 0)
	{
		handle_gap(print, ' ', print->f_w, 1);
		return (print);
	}
	num_width = get_tens(num);
	if (print->convert[0] == '-')
		left = 1;
	if (print->convert[3] == '0' && print->prec == -1 && !print->convert[0])
		print->prec = print->f_w;
	do_u(print, num, num_width, left);
	return (print);
}
