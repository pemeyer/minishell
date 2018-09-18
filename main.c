/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <pemeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:20:33 by pemeyer           #+#    #+#             */
/*   Updated: 2018/09/18 12:49:52 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define RL_BUFFSIZE 1024
#define	TOK_BUFFSIZE 64
#define TOK_DELIM " \t\r\n\a"

int		launch(char **args)
{
	pid_t 	pid;
	int 	status;
	
	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("lsh");
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

int		execute(char **args)
{
	int		i;

	if (args[0] == NULL)
	{
		return (1);
	}

	i = 0;
	while (++i < num_builtins())
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return (*builtin_func[i])(args);
		}
	}
	return (launch(args));
}

char	*read_line(void)
{
	int 	buffsize;
	int		position;
	char	*buffer;
	int 	c;

	buffsize = RL_BUFFSIZE;
	position = 0;
	if(!(buffer = malloc(sizeof(char) * buffsize)))
	{
		ft_printf("allocation error\n");
		exit (EXIT_FAILURE);
	}

	while (1)
	{
		c = getchar();

		if (c == EOF)
			exit(EXIT_SUCCESS);
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
			buffer[position] = c;
		position++;
		
		if (position >= buffsize)
		{
			buffsize += RL_BUFFSIZE;
			buffer = ft_realloc(buffer, buffsize);
			if(!buffer)
			{
				ft_printf("allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

char	**split_line(char *line)
{
	int buffsize;
	int position;
	char **tokens;
	char *token;
	char **tokens_backup;

	buffsize = TOK_BUFFSIZE;
	position = 0;
	tokens = malloc(buffsize * sizeof(char *));

	if (!tokens)
	{
		ft_printf("allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= buffsize)
		{
			buffsize += TOK_BUFFSIZE;
			tokens_backup = tokens;
			tokens = ft_realloc(tokens, buffsize * sizeof(char *));
			if (!tokens)
			{
				free(tokens_backup);
				ft_printf("allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = ft_strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}

void	shell_loop(void)
{
	char 	*line;
	char 	**args;
	int		status;
	
	status = 1;
	while (status)
	{
		printf("Pemeyer> ");
		line = read_line();
		args = split_line(line);
		status = execute(args);

		free(line);
		free(args);
	}
}

int main(void)
{
	shell_loop();
	return (0);
}
