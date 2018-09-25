/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:14:03 by pemeyer           #+#    #+#             */
/*   Updated: 2018/09/25 14:21:14 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*builtin_str[] =
{
	"help",
	"exit"
};

int		(*builtin_func[]) (char **) = 
{
	&lsh_help,
	&lsh_exit
};

int		lsh_num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

int		lsh_exit(char **args)
{
	args = NULL;
	return (0);
}


