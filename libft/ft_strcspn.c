/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 09:16:21 by pemeyer           #+#    #+#             */
/*   Updated: 2018/09/26 09:18:49 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_strcspn(const char *s1, const char *s2)
{
    int ret;

    ret = 0;
    while (*s1)
        if (ft_strchr(s2, *s1))
            return (ret);
        else
        {
            s1++;
            ret++;
        }
    return (ret);
}
