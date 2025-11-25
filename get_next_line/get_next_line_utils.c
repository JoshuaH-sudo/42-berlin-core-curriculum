/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:54 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/24 11:41:47 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_joinstr(char *dest, char *src, size_t dest_len, size_t src_len)
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

void	*ft_memmove(void *dest, const void *src, size_t n)
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

char	*parse_line_from_buffer(char *buffer, char *line, ssize_t nread)
{
	char	*line_new;
	size_t	leftover;
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
			leftover = buffer_len - (i + 1);
			if (leftover > 0)
				ft_memmove(buffer, buffer + i + 1, leftover);
			buffer[leftover] = '\0';
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
