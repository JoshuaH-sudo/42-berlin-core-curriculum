/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/26 18:01:36 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

char	*parse_line_from_buffer(char *buffer, char *line, ssize_t nread)
{
	char	*line_new;
	size_t	line_len;
	size_t	buffer_len;
	int		i;

	i = 0;
	line_len = ft_strlen(line);
	buffer_len = ft_strlen(buffer);
	while ((unsigned char)buffer[i] != '\0')
	{
		if ((unsigned char)buffer[i] == '\n')
		{
			line_new = ft_joinstr(line, buffer, line_len, i + 1);
			if ((buffer_len - (i + 1)) > 0)
				ft_memmove(buffer, (buffer + i + 1), buffer_len - (i + 1));
			buffer[(buffer_len - (i + 1))] = '\0';
			free(line);
			return (line_new);
		}
		i++;
	}
	line_new = ft_joinstr(line, buffer, line_len, nread);
	buffer[0] = '\0';
	free(line);
	return (line_new);
}

char	*get_next_line_loop(int fd, char *buffer, char *line, ssize_t nread)
{
	int		i;

	i = 0;
	while (1)
	{
		line = parse_line_from_buffer(buffer, line, nread);
		while ((unsigned char)line[i] != '\0')
		{
			if ((unsigned char)line[i] == '\n')
				return (line);
			i++;
		}
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread <= 0)
		{
			if (line[0] != '\0')
				return (line);
			free(line);
			return (NULL);
		}
		buffer[nread] = '\0';
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		nread;

	if (fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	nread = ft_strlen(buffer);
	return (get_next_line_loop(fd, buffer, line, nread));
}
