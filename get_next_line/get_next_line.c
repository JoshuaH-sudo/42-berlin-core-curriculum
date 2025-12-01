/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/12/01 08:42:10 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

char	*init_left_over(char *left_over)
{
	if (left_over)
		return (left_over);
	left_over = (char *)malloc(1 * sizeof(char));
	if (!left_over)
		return (NULL);
	left_over[0] = '\0';
	return (left_over);
}

char	*append_buffer(char *left_over, char *buffer)
{
	char	*tmp;

	tmp = ft_joinstr(left_over, buffer);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*read_buffer(int fd, char *left_over)
{
	ssize_t	nread;
	char	buffer[BUFFER_SIZE + 1];

	if (!left_over)
		left_over = init_left_over(left_over);
	// if (left_over && ft_strchr(left_over, '\n'))
	// 	return (left_over);
	nread = 1;
	while (nread > 0)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread == -1)
			return (NULL);
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

char	*extract_line(char *buffer)
{
	char	*line;
	ssize_t	i;

	i = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	return (line);
}

char	*extract_remaining(char *buffer)
{
	char	*remaining;
	ssize_t	i;
	ssize_t	len;

	i = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	len = ft_strlen(buffer);
	remaining = ft_substr(buffer, i + 1, len - (i + 1));
	free(buffer);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*left_over;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (cleanup(&left_over));
	left_over = read_buffer(fd, left_over);
	if (!left_over)
		return (NULL);
	line = extract_line(left_over);
	left_over = extract_remaining(left_over);
	return (line);
}
