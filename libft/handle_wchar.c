/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:36:09 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 08:57:55 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

static void		oct_4(wint_t c)
{
	unsigned char put[4];

	put[0] = (c >> 18) + 240;
	put[1] = ((c >> 12) & 63) + 128;
	put[2] = ((c >> 6) & 63) + 128;
	put[3] = ((c & 63) + 128);
	write(1, put, 4);
}

static void		oct_3(wint_t c)
{
	unsigned char put[3];

	put[0] = (c >> 12) + 224;
	put[1] = ((c >> 6) & 63) + 128;
	put[2] = ((c & 63) + 128);
	write(1, put, 3);
}

static void		oct_2(wint_t c)
{
	unsigned char put[2];

	put[0] = (c >> 6) + 192;
	put[1] = ((c & 63) + 128);
	write(1, put, 2);
}

static void		oct_1(wint_t c)
{
	write(1, &c, 1);
}

void			handle_wchar(wint_t c, t_print *print)
{
	if (c <= 127)
	{
		print->len += 1;
		oct_1(c);
	}
	if (c >= 127 && c <= 2047)
	{
		print->len += 2;
		oct_2(c);
	}
	if (c >= 2048 && c <= 65535)
	{
		print->len += 3;
		oct_3(c);
	}
	if (c >= 65536 && c <= 2097151)
	{
		print->len += 4;
		oct_4(c);
	}
}
