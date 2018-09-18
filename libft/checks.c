/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:27:34 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 09:15:31 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

int		checks(t_print *print)
{
	print->i++;
	convert(print);
	field_width(print);
	precision(print);
	arguments(print);
	specifier(print);
	print_printf(print);
	return (print->len);
}
