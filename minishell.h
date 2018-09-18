/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <pemeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:11:38 by pemeyer           #+#    #+#             */
/*   Updated: 2018/09/18 11:53:09 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int				cd(char **args);
void			echo(char **args);
int				lsh_exit(char **args);
extern char		*builtin_str[];
extern int		(*builtin_func[]) (char **);
int				num_builtins();

#endif
