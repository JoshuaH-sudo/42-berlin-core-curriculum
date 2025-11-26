/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:27:38 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/26 18:01:59 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <sys/types.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
char	*ft_joinstr(char *dest, char *src, size_t dest_len, size_t src_len);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*parse_line_from_buffer(char *buffer, char *line, ssize_t nread);
char	*get_next_line_loop(int fd, char *buffer, char *line, ssize_t nread);
char	*get_next_line(int fd);
#endif // GET_NEXT_LINE_H