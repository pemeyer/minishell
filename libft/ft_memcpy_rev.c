/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:21:20 by pemeyer           #+#    #+#             */
/*   Updated: 2018/05/31 10:35:30 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy_rev(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*sc;

	dst = (char *)dest;
	sc = (char *)src;
	while (n--)
	{
		dst[n] = sc[n];
	}
	return (dst);
}
