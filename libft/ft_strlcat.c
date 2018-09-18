/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:38:57 by pemeyer           #+#    #+#             */
/*   Updated: 2018/05/31 08:31:02 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t k;
	size_t j;

	i = 0;
	j = 0;
	k = ft_strlen((char *)dest);
	while (dest[j] && j < n)
		j++;
	if (!(j < n))
		return (n + ft_strlen((char *)src));
	while (i < (n - k - 1) && src[i] != '\0')
	{
		dest[k + i] = ((char *)src)[i];
		i++;
	}
	dest[j + i] = '\0';
	return (j + ft_strlen((char *)src));
}
