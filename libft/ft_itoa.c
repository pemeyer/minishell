/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:28:36 by pemeyer           #+#    #+#             */
/*   Updated: 2018/06/04 11:59:23 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void		reverse(char *s)
{
	int c;
	int i;
	int j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

static int		atoilen(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = atoilen(n);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	s[i++] = n % 10 + '0';
	while ((n /= 10) > 0)
		s[i++] = n % 10 + '0';
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	return (s);
}
