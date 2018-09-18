/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:35:00 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 08:57:06 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <limits.h>

static uintmax_t	get_num(t_print *print)
{
	uintmax_t	num;

	num = (unsigned long)(va_arg(print->args, unsigned long int));
	num = (uintmax_t)num;
	return (num);
}

static t_print		*print_u(t_print *print, char *str, int align_left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	print->len += (not_blank <= print->f_w) ? print->f_w : not_blank;
	if (!align_left)
		handle_gap(print, ' ', print->f_w - not_blank, 0);
	write(1, "0x", 2);
	handle_gap(print, '0', (print->prec - num_width) + 2, 1);
	ft_putstr(str);
	if (align_left)
		handle_gap(print, ' ', print->f_w - not_blank, 0);
	free(str);
	return (print);
}

t_print				*handle_p(t_print *print)
{
	char		*str;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(print);
	if (!(str = ft_itoa_base(num, 16, 'a')))
		exit(-1);
	if (print->convert[0] == '-')
		align_left = 1;
	if (print->prec == 0 && num == 0)
		*str = '\0';
	if (print->convert[3] == '0' && print->prec == -1 && !print->convert[0])
	{
		print->prec = print->f_w - 2;
		print->f_w = 0;
	}
	print_u(print, str, align_left);
	return (print);
}
