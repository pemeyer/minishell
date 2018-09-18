/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:05:23 by pemeyer           #+#    #+#             */
/*   Updated: 2018/09/18 13:09:26 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtok(char *str, const char *delim)
{
	static char *p;

	p = 0;
	if (str)
		p = str;
	else if (!p)
		return (0);
	str = p + strspn(p, delim);
	p = str + strcspn(str, delim);
	if (p == str)
		return (p = 0);
	*p = 0;
	p = (*p ? p + 1 : 0);
	return (str);
}
