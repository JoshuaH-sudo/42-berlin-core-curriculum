/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:06:30 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/19 17:12:47 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the string ’s’ to the specified file
// descriptor

#include <unistd.h>
#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
  if (!s)
    return;
  write(fd, s, ft_strlen(s));
  write(fd, "\n", 1);
}
