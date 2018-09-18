/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:36:25 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 08:59:18 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ctype.h>
#include "printf.h"
#include <stdarg.h>

static int		char_len(wchar_t c)
{
	int len;

	if (c <= 127)
		len = 1;
	else if (c >= 127 && c <= 2047)
		len = 2;
	else if (c >= 2048 && c <= 65535)
		len = 3;
	else
		len = 4;
	return (len);
}

static wchar_t	*wstrndup(wchar_t *s1, size_t n)
{
	wchar_t	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = (wchar_t *)malloc(sizeof(wchar_t) * n + 1)))
		exit(-1);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static wchar_t	*wstrdup(wchar_t *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (wstrndup(str, len));
}

static t_print	*do_null(t_print *print)
{
	wchar_t		*s;
	int			i;

	i = 0;
	s = wstrdup(L"(null)");
	if (print->prec > -1)
	{
		while (s[i] && print->prec-- > 0)
			handle_wchar(s[i++], print);
	}
	else
	{
		while (s[i])
			handle_wchar(s[i++], print);
	}
	free(s);
	return (print);
}

t_print			*handle_ws(t_print *print)
{
	wchar_t		*s;
	int			i;
	int			j;
	int			len;

	i = 0;
	len = 0;
	if (!(s = (wchar_t *)va_arg(print->args, wchar_t *)))
		return (do_null(print));
	while (s[i] && !(j = 0))
	{
		if (print->prec > -1 && (len + char_len(s[i])) > print->prec)
			break ;
		len += char_len(s[i++]);
	}
	if (print->convert[3] == '0' && print->convert[0] != '-')
		handle_gap(print, '0', print->f_w - len, 1);
	else if (print->convert[0] != '-')
		handle_gap(print, ' ', print->f_w - len, 1);
	while (j < i)
		handle_wchar(s[j++], print);
	if (print->convert[0] == '-')
		handle_gap(print, ' ', print->f_w - len, 1);
	return (print);
}
