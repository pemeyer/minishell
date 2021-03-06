/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 08:00:49 by pemeyer           #+#    #+#             */
/*   Updated: 2018/09/26 08:13:26 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    header(void)
{
    ft_printf("/##########################################################/\n");
    ft_printf("/#   BY: PETER-JOHN                                       #/\n");
    ft_printf("/#   BUILTINS: ECHO, CD, EXIT, ENV, SETENV, UNSETENV      #/\n");
    ft_printf("/#                                                        #/\n");
    ft_printf("/#   SHOW HELP: HELP                                      #/\n");
    ft_printf("/##########################################################/\n");
}
