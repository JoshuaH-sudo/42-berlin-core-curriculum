/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:15:27 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/24 17:30:52 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>

void	handle_string(va_list *list, int *total_printed)
{
	const char	*null_str = "(null)";
	char		*str;

	str = va_arg(*list, char *);
	if (str == NULL)
		str = (char *)null_str;
	ft_putstr_fd(str, 1);
	(*total_printed) += ft_strlen(str);
}
