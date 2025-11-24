/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:44:11 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/21 17:17:31 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	index = 0;
	while ((uc_s1[index] || uc_s2[index]) && index < n)
	{
		if (uc_s1[index] != uc_s2[index])
			return (uc_s1[index] - uc_s2[index]);
		index++;
	}
	return (0);
}
