/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:34:18 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 09:01:02 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_print		*convert(t_print *print)
{
	size_t	i;

	i = 0;
	while (print->converter[i] != '\0')
	{
		while (print->converter[i] == print->f_org[print->i])
		{
			while (print->f_org[print->i] == '-' && print->i++)
				print->convert[0] = '-';
			while (print->f_org[print->i] == '+' && print->i++)
				print->convert[1] = '+';
			while (print->f_org[print->i] == ' ' && print->i++)
				print->convert[2] = ' ';
			while (print->f_org[print->i] == '0' && print->i++)
				print->convert[3] = '0';
			while (print->f_org[print->i] == '#' && print->i++)
				print->convert[4] = '#';
			i = 0;
		}
		i++;
	}
	return (print);
}

t_print		*field_width(t_print *print)
{
	while (print->f_org[print->i] >= '0' && print->f_org[print->i] <= '9')
	{
		print->f_w *= 10;
		print->f_w += (print->f_org[print->i] - 48);
		print->i++;
	}
	return (print);
}

t_print		*precision(t_print *print)
{
	while (print->f_org[print->i] == '.')
	{
		print->i++;
		print->prec = 0;
	}
	while (print->f_org[print->i] >= '0' && print->f_org[print->i] <= '9')
	{
		print->prec *= 10;
		print->prec += (print->f_org[print->i] - 48);
		print->i++;
	}
	return (print);
}

t_print		*arguments(t_print *print)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (print->argument[i] != '\0')
	{
		while (print->argument[i] == print->f_org[print->i])
		{
			print->a_f[j] = print->f_org[print->i];
			print->a_f[j + 1] = '\0';
			print->i++;
			j++;
		}
		i++;
	}
	return (print);
}

t_print		*specifier(t_print *print)
{
	size_t	i;

	i = 0;
	while (print->specifier[i] != '\0')
	{
		if (print->specifier[i] == print->f_org[print->i])
			print->s_f = print->specifier[i];
		i++;
	}
	return (print);
}
