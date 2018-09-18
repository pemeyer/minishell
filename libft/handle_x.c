/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:37:07 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 09:00:33 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <limits.h>

static void			print_leading_zero(uintmax_t num, char hash, char x)
{
	if (num)
	{
		if (hash == '#' && x == 'x')
			write(1, "0x", 2);
		if (hash == '#' && x == 'X')
			write(1, "0X", 2);
	}
}

static uintmax_t	get_num(t_print *print)
{
	uintmax_t	num;

	if (ft_strcmp(print->a_f, "hh") == 0)
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

static t_print		*do_x(t_print *print, uintmax_t num, char *str,
		int align_left)
{
	int			n_b;
	int			n_w;

	if ((n_w = ft_strlen(str)) && print->convert[4] == '#' && num &&
			print->convert[3] == '0' && print->f_w)
		n_w += 2;
	else if ((n_w = ft_strlen(str)) && print->convert[4] == '#' && num)
	{
		print->f_w -= 2;
		print->len += 2;
	}
	n_b = (n_w <= print->prec && print->prec > 0) ? print->prec : n_w;
	print->len += (n_b <= print->f_w) ? print->f_w : n_b;
	if (!align_left)
		handle_gap(print, ' ', print->f_w - n_b, 0);
	print_leading_zero(num, print->convert[4], print->s_f);
	handle_gap(print, '0', print->prec - n_w, 0);
	ft_putstr(str);
	if (align_left)
		handle_gap(print, ' ', print->f_w - n_b, 0);
	return (print);
}

t_print				*handle_x(t_print *print)
{
	char		*str;
	char		c;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(print);
	if (num == 0 && print->prec == 0)
	{
		handle_gap(print, ' ', print->f_w, 1);
		return (print);
	}
	c = 'a';
	if (print->s_f == 'X')
		c = 'A';
	if (!(str = ft_itoa_base(num, 16, c)))
		exit(-1);
	if (print->convert[0] == '-')
		align_left = 1;
	if (print->convert[3] == '0' && print->prec == -1 && !print->convert[0])
		print->prec = print->f_w;
	do_x(print, num, str, align_left);
	free(str);
	return (print);
}
