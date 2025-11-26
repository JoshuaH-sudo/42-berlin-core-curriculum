/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:15:27 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/26 15:58:21 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>

void	handle_char(va_list *list, int *total_printed)
{
	char	c;

	c = (char)va_arg(*list, int);
	ft_putchar_fd(c, 1);
	(*total_printed)++;
}
