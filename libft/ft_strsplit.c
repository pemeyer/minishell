/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:38:41 by pemeyer           #+#    #+#             */
/*   Updated: 2018/07/23 09:01:52 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_cntw(char const *s, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	if (s != '\0')
	{
		if (!(tab = (char **)malloc(sizeof(char *) * (ft_cntw(s, c)) + 1)))
			return (NULL);
		while (s[i])
		{
			while (s[i] == c)
				i++;
			j = i;
			while (s[i] && s[i] != c)
				i++;
			if (i > j)
				tab[k++] = ft_strndup(s + j, i - j);
		}
		tab[k] = NULL;
		return (tab);
	}
	return (NULL);
}
