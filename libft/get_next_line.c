/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:20:37 by pemeyer           #+#    #+#             */
/*   Updated: 2018/08/13 12:05:26 by pemeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		new_line(char **st, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (st[fd][len] != '\0' && st[fd][len] != '\n')
		len++;
	if (st[fd][len] == '\0')
	{
		*line = ft_strdup(st[fd]);
		ft_strdel(&st[fd]);
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
	}
	else if (st[fd][len] == '\n')
	{
		*line = ft_strsub(st[fd], 0, len);
		tmp = ft_strdup(st[fd] + len + 1);
		free(st[fd]);
		st[fd] = tmp;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;
	static char		*st[250];

	if (line == NULL || read(fd, buf, 0) < 0 || fd < 0)
		return (-1);
	if (st[fd] == NULL)
		st[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(st[fd], buf);
		free(st[fd]);
		st[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && st[fd][0] == '\0')
		return (0);
	else
		return (new_line(st, line, fd, ret));
}
