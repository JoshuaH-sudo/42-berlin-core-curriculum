/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/23 15:31:04 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	ssize_t			nread;

	nread = 1;
	line = "";
	if (fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		buffer[0] = '\0';
	}
	if (!buffer)
		return (NULL);
	while (nread > 0)
	{
		if (nread <= 0)
			return (NULL);
		printf("buffer: ---\n%s\n---\n", buffer);
		line = parse_line_from_buffer(buffer, line, nread);
		if (!line)
			return (NULL);
		printf("line after parse: %s\n", line);
		if (find_newline(line) != -1)
			break ;
		nread = read(fd, buffer, BUFFER_SIZE);
		buffer[nread] = '\0';
	}
	return (line);
}
