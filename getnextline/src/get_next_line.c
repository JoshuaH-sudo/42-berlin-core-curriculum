/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/23 17:54:13 by jhoban           ###   ########.fr       */
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
	ssize_t nread;

	if (fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	// Allocate an empty string for line, to be accumulated
	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';

	// First, process any data already in buffer
	nread = ft_strlen(buffer);
	while (1)
	{
		line = parse_line_from_buffer(buffer, line, nread);
		if (find_newline(line) != -1)
			break;
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread <= 0)
		{
			// If we have accumulated any data, return it (last line, no newline)
			if (line[0] != '\0')
				return line;
			free(line);
			return NULL;
		}
		buffer[nread] = '\0';
	}
	return line;
}
