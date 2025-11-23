/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/23 10:08:53 by jhoban           ###   ########.fr       */
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
	char			*line_new;
	ssize_t			nread;

	nread = 1;
	line = NULL;
	if (fd < 0)
		return (NULL);
	while (nread > 0)
	{
		line_new = parse_line_from_buffer(buffer, line, nread);
		if (line_new == NULL)
			return (NULL);
		if (find_newline(line_new) != -1)
			return (line_new);
		line = line_new;
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread <= 0)
			break ;
		buffer[nread] = '\0';
	}
	free(line);
	return (NULL);
}
