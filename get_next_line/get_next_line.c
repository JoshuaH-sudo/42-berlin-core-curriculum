/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/27 16:41:20 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include <stdio.h>

char	*get_next_line_loop(int fd, char *buffer, char *left_over)
{
	int		i;
	ssize_t	nread;
	char	*tmp;

	i = 0;
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
		if (!left_over)
		{
			left_over = (char *)malloc(1 * sizeof(char));
			if (!left_over)
				return (NULL);
			left_over[0] = '\0';
		}
		tmp = left_over;
		left_over = ft_joinstr(left_over, buffer);
		free(tmp);
		if (!left_over)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_over);
}

char *extract_line(char *line_buffer)
{
    char    *left_over;
    ssize_t    i;
    
    i = 0;
    while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
        i++;
    if (line_buffer[i] == 0 || line_buffer[1] == 0)
        return (NULL);
    left_over = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
    if (*left_over == 0)
    {
        free(left_over);
        left_over = NULL;
    }
    line_buffer[i + 1] = 0;
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
		free(left_over);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = get_next_line_loop(fd, buffer, left_over);
	left_over = extract_line(line);
	free(buffer);
	return (line);
}
