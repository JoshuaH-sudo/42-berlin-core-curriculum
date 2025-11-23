/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:54 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/23 18:01:22 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

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
	int		newline_index;

	newline_index = find_newline(buffer);
	if (newline_index != -1)
	{
		line_new = ft_joinstr(line, buffer, ft_strlen(line), newline_index + 1);
		leftover = ft_strlen(buffer) - (newline_index + 1);
		if (leftover > 0)
			ft_memmove(buffer, buffer + newline_index + 1, leftover);
		buffer[leftover] = '\0';
		free(line);
		return (line_new);
	}
	line_new = ft_joinstr(line, buffer, ft_strlen(line), nread);
	buffer[0] = '\0';
	free(line);
	return (line_new);
}

static char	*get_next_line_loop(int fd, char *buffer, char *line, ssize_t nread)
{
	while (1)
	{
		line = parse_line_from_buffer(buffer, line, nread);
		if (find_newline(line) != -1)
			return (line);
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
