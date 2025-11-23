/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:27:38 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/23 09:40:19 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
#include <string.h>

char  *get_next_line(int fd);
size_t  ft_strlen(const char *s);
int   find_newline(char *str);
char  *ft_joinstr(char *dest, char *src, size_t dest_len, size_t src_len);
char  *parse_line_from_buffer(char *buffer, char *line, ssize_t nread);
void  *ft_memmove(void *dest, const void *src, size_t n);
# endif