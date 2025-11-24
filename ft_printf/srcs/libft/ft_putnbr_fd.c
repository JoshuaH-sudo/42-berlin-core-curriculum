/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:06:30 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/20 10:34:42 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the integer 'n' to the specified file
// descriptor

#include "libft.h"
#include <unistd.h>

static void	convert(int nb, int fd)
{
	int		mod;
	char	letter;

	if (nb != 0)
	{
		mod = nb % 10;
		nb = nb / 10;
		convert(nb, fd);
		if (mod < 0)
			mod = 0 - mod;
		letter = mod + '0';
		write(fd, &letter, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	convert(n, fd);
}
