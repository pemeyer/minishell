/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:33:38 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 08:56:34 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <limits.h>

static void			print_leading_zero(uintmax_t num, char hash)
{
	if (hash == '#' && num)
		write(1, "0", 1);
}

static uintmax_t	get_num(t_print *print)
{
	uintmax_t	num;

	if (print->s_f == 'O')
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

static t_print		*print_u(t_print *print, uintmax_t num, char *str, int left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str);
	if (print->convert[4] == '#' && num)
		num_width++;
	not_blank = num_width;
	if (num_width <= print->prec && print->prec > 0)
		not_blank = print->prec;
	print->len += (not_blank <= print->f_w) ? print->f_w : not_blank;
	if (!left)
		handle_gap(print, ' ', print->f_w - not_blank, 0);
	print_leading_zero(num, print->convert[4]);
	handle_gap(print, '0', print->prec - num_width, 0);
	ft_putstr(str);
	free(str);
	if (left)
		handle_gap(print, ' ', print->f_w - not_blank, 0);
	return (print);
}

t_print				*handle_o(t_print *print)
{
	char		*str;
	uintmax_t	num;
	int			left;

	left = 0;
	num = get_num(print);
	if (num == 0 && print->prec == 0 && print->convert[4] != '#')
	{
		handle_gap(print, ' ', print->f_w, 1);
		return (print);
	}
	if (!(str = ft_itoa_base(num, 8, 'a')))
		exit(-1);
	if (print->convert[0] == '-')
		left = 1;
	if (print->convert[3] == '0' && print->prec == -1 && !print->convert[0])
		print->prec = print->f_w;
	print_u(print, num, str, left);
	return (print);
}
