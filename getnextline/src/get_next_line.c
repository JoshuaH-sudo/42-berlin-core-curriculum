/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/22 15:06:11 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
  size_t  len;

  len = 0;
  while (s[len] != '\0')
    len++;
  return (len);
}

int   find_newline(char *str)
{
  int i;

  i = 0;
  while ((unsigned char)str[i] != '\0')
  {
    if ((unsigned char)str[i] == '\n')
      return (i);
    i++;
  }
  return (-1);
}

char  *append_str(char *dest, char *src, size_t dest_len, size_t src_len)
{
  char *new_str;
  size_t i;

  new_str = (char *)malloc(dest_len + src_len + 1);
  if (!new_str)
    return (NULL);
  i = 0;
  while (i < dest_len)
  {
    new_str[i] = dest[i];
    i++;
  }
  size_t j = 0;
  while (j < src_len)
  {
    new_str[i + j] = src[j];
    j++;
  }
  new_str[dest_len + src_len] = '\0';
  return (new_str);
}

// char  *get_next_line(int fd)
// {
//   static char buffer[BUFFER_SIZE];
//   static size_t leftover;
//   ssize_t nread;
//   char *line;
//   int newline_index;

//   leftover = 0;
//   newline_index = -1;
//   nread = 0;
//   line = (char *)malloc(BUFFER_SIZE);
//   if (fd < 0)
//     return (NULL);
//   if (leftover == 0)
//   {
//     nread = read(fd, buffer, BUFFER_SIZE); 
//     if (nread < 0)
//       return (NULL);
//     buffer[nread] = '\0';
//     leftover = nread;
//   }
//   while((nread = read(fd,buffer, 1)) > 0)
//   {
//     newline_index = find_newline(buffer);
//     if (newline_index != -1)
//     {
//       line = append_str(line, buffer, ft_strlen(line), newline_index);
//       break;
//     }
//     line = append_str(line, buffer, ft_strlen(line), ft_strlen(buffer));
//   }
//   leftover = 0;
//   return (line);
// }

char *get_next_line(int fd)
{
  static char *buffer;
  ssize_t nread;
  size_t buffer_len;
  int newline_index;
  char *line;

  if (fd < 0)
    return (NULL);
  if (!buffer)
  {
    buffer = (char *)malloc(BUFFER_SIZE);
    line = (char *)malloc(BUFFER_SIZE);
    if (!buffer)
      return (NULL);
    buffer[0] = '\0';
  }

  buffer_len = ft_strlen(buffer);
  if (buffer_len == 0)
  {
    nread = read(fd, buffer, BUFFER_SIZE);
    if (nread <= 0)
    {
      free(buffer);
      buffer = NULL;
      return (NULL);
    }
  }
  if (buffer_len > 0)
  {
    printf("checking existing buffer: \n----\n%s\n----\n", buffer);
    newline_index = find_newline(buffer);
    if (newline_index != -1)
    {
      line = append_str(line, buffer, ft_strlen(line), newline_index);
      buffer += (newline_index + 1);
      return (line);
    }
  }
  return (line);
}