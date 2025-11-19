/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:06:30 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/19 17:08:43 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the character ’c’ to the specified file
// descriptor

#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
  write(fd, &c, 1);
}
