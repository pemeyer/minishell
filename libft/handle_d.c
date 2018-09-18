/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:32:37 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 08:56:10 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <limits.h>

static intmax_t	get_num(t_print *print)
{
	intmax_t	num;

	if (print->s_f == 'D')
		num = (long)(va_arg(print->args, long int));
	else if (ft_strcmp(print->a_f, "hh") == 0)
		num = (signed char)(va_arg(print->args, int));
	else if (ft_strcmp(print->a_f, "h") == 0)
		num = (short)(va_arg(print->args, int));
	else if (ft_strcmp(print->a_f, "ll") == 0)
		num = (long long)(va_arg(print->args, long long int));
	else if (ft_strcmp(print->a_f, "l") == 0)
		num = (long)(va_arg(print->args, long int));
	else if (ft_strcmp(print->a_f, "j") == 0)
		num = (intmax_t)(va_arg(print->args, intmax_t));
	else if (ft_strcmp(print->a_f, "z") == 0)
		num = (size_t)(va_arg(print->args, size_t));
	else
		num = (int)(va_arg(print->args, int));
	num = (intmax_t)num;
	return (num);
}

static int		get_tens(intmax_t num)
{
	int tens;

	if (num < 0)
		num *= -1;
	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static char		get_negative_placeholder(t_print *print, int is_negative)
{
	char	*tmp;

	tmp = print->convert;
	if (is_negative)
		return ('-');
	if (tmp[1] == '+')
		return ('+');
	if (tmp[2] == ' ')
		return (' ');
	return ('\0');
}

static t_print	*do_d(t_print *print, intmax_t num, int num_width,
		int align_left)
{
	int			not_blank;
	char		negative_placeholder;
	int			is_negative;

	is_negative = (num < 0) ? 1 : 0;
	num *= (is_negative && num != (-9223372036854775807 - 1)) ? -1 : 1;
	negative_placeholder = get_negative_placeholder(print, is_negative);
	not_blank = num_width;
	if (num_width <= print->prec && print->prec >= 0)
		not_blank = print->prec;
	if (negative_placeholder)
		not_blank++;
	print->len += (not_blank <= print->f_w) ? print->f_w : not_blank;
	if (!align_left)
		handle_gap(print, ' ', print->f_w - not_blank, 0);
	if (negative_placeholder)
		write(1, &negative_placeholder, 1);
	handle_gap(print, '0', print->prec - num_width, 0);
	if (num != (-9223372036854775807 - 1))
		ft_putnbrmax_fd(num, 1);
	else if ((print->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (align_left)
		handle_gap(print, ' ', print->f_w - not_blank, 0);
	return (print);
}

t_print			*handle_d(t_print *print)
{
	intmax_t	num;
	int			num_width;
	int			align_left;

	num = get_num(print);
	if (num == 0 && print->prec == 0)
	{
		if (print->convert[1] == '+')
			handle_wchar('+', print);
		if (print->convert[2] == ' ')
			handle_wchar(' ', print);
		handle_gap(print, ' ', print->f_w, 1);
		return (print);
	}
	num_width = get_tens(num);
	align_left = (print->convert[0] == '-') ? 1 : 0;
	if (print->convert[3] == '0' && print->prec == -1 && !print->convert[0])
	{
		print->prec = print->f_w;
		if (num < 0 || print->convert[2] || print->convert[1]
				|| print->convert[0])
			print->prec--;
	}
	do_d(print, num, num_width, align_left);
	return (print);
}
