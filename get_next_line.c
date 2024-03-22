/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:02:20 by saandria          #+#    #+#             */
/*   Updated: 2024/03/20 09:32:03 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//lecture du fichier
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
//		if (!content)
//			content = ft_strdup("");
	}
	free(buff);
	return (content);
}

//definir la ligne
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
	static char	*content;
	char		*line;
	char		*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(content);
		free(buff);
		return (NULL);
	}
	if (!buff)
		return (NULL);
	line = read_and_return(fd, content, buff);
	if (!line || *line == '\0')
	{
		//free(line);
		return (NULL);
	}
	content = def_and_get_line(line);
	return (line);
}
