/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:52:00 by pemeyer           #+#    #+#             */
/*   Updated: 2018/05/29 09:52:09 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s, const char *subs, size_t n)
{
	size_t	i;

	i = ft_strlen((char *)subs);
	if (*subs == '\0')
		return ((char *)s);
	while (*s != '\0' && n-- >= i)
	{
		if (*s == *subs && ft_memcmp(s, subs, i) == 0)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
