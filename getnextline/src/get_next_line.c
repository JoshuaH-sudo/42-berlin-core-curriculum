/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/20 17:23:06 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

// char  *find_newline(char *str)
// {
//   char *ptr;

//   ptr = str;
//   while (*ptr != '\0' && *ptr != '\n' && i < BUFFER_SIZE)
//   {
//     ptr++;
//   }
//   return (ptr);
// }

// char  *get_line(char *str)
// {
//   int i;
//   int len;
//   char *line;

//   len = count_to_newline(str);
//   line = (char *)malloc((len + 1) * sizeof(char));
//   printf("Allocated %d bytes for line\n", len + 1);
//   if (!line)
//     return (NULL);
//   i = 0;
//   while (i < len)
//   {
//     line[i] = str[i];
//     i++;
//   }
//   line[i] = '\0';
//   return (line);
// }

char  *get_next_line(int fd)
{
  // static int chunk_index = 0;
  char buffer[BUFFER_SIZE + 1];
  char *line;
  ssize_t nread = 0;

  line = NULL;
  if (fd < 0)
    return (NULL);
  while(read(fd, buffer, BUFFER_SIZE) > 0)
  {
    printf("Read %zd bytes from fd %d\n", nread, fd);
    printf("Buffer content: %s\n", buffer);
  }
  return (line);
}