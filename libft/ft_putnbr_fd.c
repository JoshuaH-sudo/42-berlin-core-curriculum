/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:06:30 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/19 17:22:24 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the integer 'n' to the specified file
// descriptor

#include <unistd.h>
#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
  char *str;

  str = ft_itoa(n);
  if (!str)
    return;
  write(fd, str, ft_strlen(str));
}
