/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:30:55 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 09:00:48 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_print	*init(t_print *print)
{
	print->len = 0;
	print->i = 0;
	print->specifier = "scSCdDiuUoOxXbp%";
	print->converter = "-+ 0#";
	print->argument = "lhjz";
	print->f_org = (char *)print->format;
	print->f_copy = (char *)print->format;
	return (print);
}

t_print	*reinit(t_print *print)
{
	print->s_f = '\0';
	print->convert[0] = '\0';
	print->convert[1] = '\0';
	print->convert[2] = '\0';
	print->convert[3] = '\0';
	print->convert[4] = '\0';
	print->convert[5] = '\0';
	print->a_f[0] = '\0';
	print->a_f[1] = '\0';
	print->prec = -1;
	print->f_w = 0;
	return (print);
}
