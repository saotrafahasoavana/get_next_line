/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:18:28 by saandria          #+#    #+#             */
/*   Updated: 2024/03/20 10:51:24 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_and_return(int fd, char *content, char *buff)
{
	int	rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(content);
			free(buff);
			return (NULL);
		}
		if (rd == 0)
			break ;
		*(buff + rd) = '\0';
		content = ft_strjoin(content, buff);
	}
	free(buff);
	return (content);
}

static char	*def_and_get_line(char *line)
{
	char	*content;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	content = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!content)
		free(content);
	line[i + 1] = '\0';
	return (content);
}

char	*get_next_line(int fd)
{
	static char	*content[MAX_FD];
	char		*line;
	char		*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(content[fd]);
		free(buff);
		return (NULL);
	}
	if (!buff)
		return (NULL);
	line = read_and_return(fd, content[fd], buff);
	if (!line || *line == '\0')
		return (NULL);
	content[fd] = def_and_get_line(line);
	return (line);
}
