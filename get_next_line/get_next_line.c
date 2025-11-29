/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/29 10:06:48 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

char	*init_left_over(void)
{
	char	*left_over;

	left_over = (char *)malloc(1 * sizeof(char));
	if (!left_over)
		return (NULL);
	left_over[0] = '\0';
	return (left_over);
}

char	*append_buffer(char *left_over, char *buffer)
{
	char	*tmp;
	char	*new_left_over;

	if (!left_over)
		left_over = init_left_over();
	if (!left_over)
		return (NULL);
	tmp = left_over;
	new_left_over = ft_joinstr(left_over, buffer);
	free(tmp);
	return (new_left_over);
}

char	*read_buffer(int fd, char *buffer, char *left_over)
{
	ssize_t	nread;

	nread = 1;
	while (nread > 0)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread == -1)
		{
			if (left_over)
				free(left_over);
			return (NULL);
		}
		if (nread == 0)
			break ;
		buffer[nread] = '\0';
		left_over = append_buffer(left_over, buffer);
		if (!left_over)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_over);
}

char	*extract_line(char *line_buffer)
{
	char	*left_over;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0' || line_buffer[1] == '\0')
		return (NULL);
	left_over = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_over == 0)
	{
		free(left_over);
		left_over = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (left_over);
}

char	*get_next_line(int fd)
{
	static char	*left_over;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		if (left_over)
			free(left_over);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_buffer(fd, buffer, left_over);
	free(buffer);
	if (!line)
	{
		left_over = NULL;
		return (NULL);
	}
	left_over = extract_line(line);
	return (line);
}
