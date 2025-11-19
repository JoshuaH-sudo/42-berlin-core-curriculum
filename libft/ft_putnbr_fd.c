/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:06:30 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/19 17:12:19 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the integer 'n' to the specified file
// descriptor

#include <unistd.h>

void ft_putchar_fd(int n, int fd)
{
  char *str;

  str = ft_itoa(n);
  write(fd, str, ft_strlen(str));
}
