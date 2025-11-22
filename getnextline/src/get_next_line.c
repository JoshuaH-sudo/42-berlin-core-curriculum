/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/22 18:24:29 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	find_newline(char *str)
{
	int	i;

	i = 0;
	while ((unsigned char)str[i] != '\0')
	{
		if ((unsigned char)str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*append_str(char *dest, char *src, size_t dest_len, size_t src_len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = (char *)malloc((dest_len + src_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < dest_len)
	{
		new_str[i] = dest[i];
		i++;
	}
	j = 0;
	while (j < src_len)
	{
		new_str[i + j] = src[j];
		j++;
	}
	new_str[dest_len + src_len] = '\0';
	return (new_str);
}

char	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dest;
	s = src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char *line;
	char *line_new;
	ssize_t nread;
	// size_t buffer_len;
	size_t leftover;
	int newline_index;

	newline_index = -1;
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
	newline_index = find_newline(buffer);
	if (newline_index != -1)
	{
		// Append only up to and including the newline
		line_new = append_str(line, buffer, ft_strlen(line), newline_index + 1);
		free(line);
		// Shift leftover to front
		leftover = ft_strlen(buffer) - (newline_index + 1);
		if (leftover > 0)
			ft_memmove(buffer, buffer + newline_index + 1, leftover);
		buffer[leftover] = '\0';
		return (line_new);
	}
	while ((nread = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nread] = '\0';
		newline_index = find_newline(buffer);
		if (newline_index != -1)
		{
			// Append up to and including the newline
			line_new = append_str(line, buffer, ft_strlen(line), newline_index + 1);
			free(line);
			line = line_new;
			// Shift leftover
			leftover = nread - (newline_index + 1);
			if (leftover > 0)
				ft_memmove(buffer, buffer + newline_index + 1, leftover);
			buffer[leftover] = '\0';
			return (line);
		}
		else
		{
			// Append the whole buffer
			line_new = append_str(line, buffer, ft_strlen(line), nread);
			free(line);
			line = line_new;
			buffer[0] = '\0';
		}
	}
	// If we have accumulated any data, return it
	if (ft_strlen(line) > 0)
		return (line);
	free(line);
	return (NULL);
}