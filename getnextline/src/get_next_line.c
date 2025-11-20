/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:28:44 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/20 14:36:44 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char  *get_next_line(int fd)
{
  char c;
  int bytes;

  while((bytes = read(fd, &c, sizeof(c)) > 0))
  {
    if (bytes < 0)
      return (NULL);
    write(1, &c, 1);
    if (c == '\n')
      break ;
  }
  return (NULL);
}