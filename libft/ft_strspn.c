/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 09:11:50 by pemeyer           #+#    #+#             */
/*   Updated: 2018/09/26 09:13:41 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_strspn(const char *s1, const char *s2)
{
    int ret;

    ret = 0;
    while (*s1 && ft_strchr(s2, *s1++))
        ret++;
    return (ret);
}
