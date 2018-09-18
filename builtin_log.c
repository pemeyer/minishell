/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_log.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:46:02 by pemeyer           #+#    #+#             */
/*   Updated: 2018/09/18 11:53:13 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*builtin_str[] = 
{
	"cd",
	"exit"
};

int		(*builtin_func[]) (char **) = 
{
	&cd,
	&lsh_exit
};

int		num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}
