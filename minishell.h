/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:14:03 by pemeyer           #+#    #+#             */
/*   Updated: 2018/09/26 11:51:42 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
# define QUOTE(x) (x == '"' || x == '\'')

void    header(void);
int     launch(char **args);
int     lsh_exit(void);
int     lsh_cd(char **args);
int     lsh_echo(char **args);
int     lsh_help(char **args);

