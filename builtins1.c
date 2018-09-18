/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:55:24 by pemeyer           #+#    #+#             */
/*   Updated: 2018/09/18 13:13:50 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cd(char **args)
{
	if (args[1] == NULL)
		ft_printf("expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}
	return (1);
}

int		lsh_exit(char **args)
{
	args = NULL;
	return (0);
}

/*int		echo(char **args)
{
	int		i;
	int 	n_flag;

	n_flag = 0;
	if (!args[0])
}*/
