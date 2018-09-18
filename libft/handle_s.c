/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:35:31 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 08:57:18 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

t_print			*handle_s(t_print *print)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	s = va_arg(print->args, char *);
	if (print->prec > -1 && s)
		s = ft_strndup(s, print->prec);
	else if (print->prec == -1 && s)
		s = ft_strdup(s);
	else if (print->prec > -1 && !s)
		s = ft_strndup("(null)", print->prec);
	else if (print->prec == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	print->len += len;
	if (print->convert[3] == '0' && print->convert[0] != '-')
		handle_gap(print, '0', print->f_w - len, 1);
	else if (print->convert[0] != '-')
		handle_gap(print, ' ', print->f_w - len, 1);
	ft_putstr(s);
	if (print->convert[0] == '-')
		handle_gap(print, ' ', print->f_w - len, 1);
	free(s);
	return (print);
}
