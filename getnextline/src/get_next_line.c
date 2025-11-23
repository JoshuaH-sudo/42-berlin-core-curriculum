/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/23 09:41:05 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char *buffer;
	char *line;
	char *line_new;
	ssize_t nread;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (!line)
	{
		line = (char *)malloc(BUFFER_SIZE + 1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	// Try to parse from buffer first
	line_new = parse_line_from_buffer(buffer, line, ft_strlen(buffer));
	if (find_newline(line_new) != -1)
		return line_new;
	line = line_new;
	while ((nread = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nread] = '\0';
		line_new = parse_line_from_buffer(buffer, line, nread);
		if (find_newline(line_new) != -1)
			return line_new;
		line = line_new;
	}
	// If we have accumulated any data, return it
	if (line && ft_strlen(line) > 0)
		return line;
	free(line);
	return NULL;
}