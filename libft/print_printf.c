/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:35:13 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/07 09:01:16 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

t_print		*print_printf(t_print *print)
{
	char	*flag;

	flag = &print->s_f;
	if (*flag == 'd' || *flag == 'i' || *flag == 'D')
		handle_d(print);
	else if (*flag == 'c' || *flag == 'C')
		handle_c(print);
	else if (*flag == 's' && ft_strcmp(print->a_f, "l") == 0)
		handle_ws(print);
	else if (*flag == 's')
		handle_s(print);
	else if (*flag == 'S')
		handle_ws(print);
	else if (*flag == 'u' || *flag == 'U')
		handle_u(print);
	else if (*flag == 'x' || *flag == 'X')
		handle_x(print);
	else if (*flag == 'o' || *flag == 'O')
		handle_o(print);
	else if (*flag == 'p')
		handle_p(print);
	else
		handle_other(print);
	return (print);
}
