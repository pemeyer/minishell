/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:04:36 by pemeyer           #+#    #+#             */
/*   Updated: 2018/09/26 12:01:25 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     lsh_exit(void)
{
    return (0);
}

int     lsh_cd(char **args)
{
    if (args[1] == NULL)
    {
        ft_printf("Bash error: expected argument to \"cd\"");
    }
    else
    {
        if (chdir(args[1]) != 0)
            perror("Bash error");
    }
    return (1);
}

static void echo_print(char **str, int pos)
{
    int start;
    int end;
    int str_len;
    
    start = QUOTE(str[pos][0]);
    str_len = (int)ft_strlen(str[pos]);
    end = QUOTE(str[pos][str_len -1]);
    if (end && start)
        ft_putnstr(str[pos] + 1, -1);
    else if (end)
        ft_putnstr(str[pos], -1);
    else if (start)
        ft_putstr(str[pos] + 1);
    else
        ft_putstr(str[pos]);
    if(str[pos + 1])
        ft_putchar(' ');
}

int     lsh_echo(char **args)
{
    int     i;
    int     n_flag;
    
    n_flag = 0;
    if (!args[0])
    {
        write(1, "\n", 1);
        return (1);
    }
    else if (args[0][0] == '-' && args[0][1] == 'n' && args[0][2] ==     '\0')
        n_flag = 1;
    i = 0;
    if (n_flag)
        ++i;
    while (args[++i])
    {
        echo_print(args, i);
        if (!args[i + 1] && !n_flag)
            ft_putchar('\n');
    }
    return (1);
}

int     lsh_help(char **args)
{
    args = NULL;

    ft_printf("Peter-John Meyer's SHELL\n");
    ft_printf("Type program names and arguments and hit enter.\n");
    ft_printf("The following commands are built in: \n\nECHO\nCD\nEXIT\nENV\nSETENV\nUNSETENV\n");
    return (1);
}
