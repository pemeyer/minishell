/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:13:20 by pemeyer           #+#    #+#             */
/*   Updated: 2018/09/26 12:05:17 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     shell_execute(char **args)
{
    if (args[0] == NULL)
        return (1);
    if (ft_strcmp(args[0], "exit") == 0)
        return (lsh_exit());
    else if (ft_strcmp(args[0], "echo") == 0)
        return (lsh_echo(args));
    else if (ft_strcmp(args[0], "cd") == 0)
        return (lsh_cd(args));
    else if (ft_strcmp(args[0], "help") == 0)
        return (lsh_help(args));
    return (launch(args));
}

int     launch(char **args)
{
    pid_t   pid;
    int     status;

    pid = fork();
    if (pid == 0)
    {
        if (execve(args[0], args, NULL) == -1)
        {
            perror("lsh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("lsh");
    }
    else
    {
        while (!WIFEXITED(status) && !WIFSIGNALED(status))
            waitpid(pid, &status, WUNTRACED);
    }
    return (1);
}

char    *read_line(void)
{
    char *line = NULL;
    get_next_line(0, &line);
    return (line);
    ft_strdel(&line);
}

void    shell_loop(void)
{
    char    *line;
    char    **args;
    int     status;

    status = 1;
    while (status)
    {
        ft_printf("> ");
        line = read_line();
        args = ft_strsplit(line, ' ');
        status = shell_execute(args);

        free(line);
        free(args);
    }
}

int		main(void)
{
    header();
    shell_loop();
	return (0);
}
