/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/30 21:05:07 by jhoban           ###   ########.fr       */
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
	char	*new_left_over;

	left_over = init_left_over(left_over);
	if (!left_over)
		return (NULL);
	tmp = left_over;
	new_left_over = ft_joinstr(left_over, buffer);
	if (!new_left_over)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (new_left_over);
}

char	*read_buffer(int fd, char *buffer, char **left_over_ptr)
{
	ssize_t	nread;
	char	*left_over;

	left_over = *left_over_ptr;
	nread = 1;
	if (left_over && (ft_strchr(left_over, '\n') || ft_strchr(buffer, '\0')))
		return (left_over);
	while (nread > 0)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread == -1)
			return (cleanup(left_over_ptr));
		if (nread == 0)
			break ;
		buffer[nread] = '\0';
		left_over = append_buffer(left_over, buffer);
		if (!left_over)
			return (cleanup(left_over_ptr));
		*left_over_ptr = left_over;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_over);
}

char	*extract_line(char **line_buffer)
{
	char	*left_over;
	char	*line;
	ssize_t	i;

	i = 0;
	while ((*line_buffer)[i] != '\n' && (*line_buffer)[i] != '\0')
		i++;
	if ((*line_buffer)[i] == '\0')
		return (NULL);
	left_over = ft_substr(*line_buffer, i + 1, ft_strlen(*line_buffer) - i);
	if (!left_over)
		return (NULL);
	line = ft_substr(*line_buffer, 0, i + 1);
	free(*line_buffer);
	*line_buffer = left_over;
	if (!line)
		return (cleanup(line_buffer));
	if ((*line_buffer)[0] == '\0')
		cleanup(line_buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*left_over;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (cleanup(&left_over));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (cleanup(&left_over));
	left_over = read_buffer(fd, buffer, &left_over);
	free(buffer);
	if (!left_over)
		return (NULL);
	line = extract_line(&left_over);
	if (!line)
	{
		line = left_over;
		left_over = NULL;
	}
	return (line);
}
