/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:29:41 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 08:55:24 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"
#include "printf.h"
#include <stdlib.h>

int		ft_vprintf(t_print *print)
{
	if (ft_strcmp(print->f_copy, "%") == 0)
		return (0);
	while (print->f_copy[print->i] != '\0')
	{
		if (print->f_copy[print->i] == '%')
		{
			reinit(print);
			checks(print);
		}
		else
		{
			write(1, &print->f_copy[print->i], 1);
			print->len++;
		}
		print->i++;
	}
	return (print->len);
}

int		ft_printf(const char *format, ...)
{
	t_print *print;

	if (!(print = (t_print*)malloc(sizeof(t_print))))
		return (-1);
	print->format = format;
	print = init(print);
	if (format)
	{
		va_start(print->args, format);
		print->len = ft_vprintf(print);
		va_end(print->args);
	}
	free(print);
	return (print->len);
}
