/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:17:05 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/17 21:17:06 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

#ifndef LIBFT_H

#define LIBFT_H

void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
  
#endif // LIBFT_H