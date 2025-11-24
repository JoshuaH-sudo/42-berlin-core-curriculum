/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:16:35 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/24 17:31:15 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
int		ft_printf(const char *format, ...);
void	handle_argument(const char *ptr, va_list *list, int *total_printed);
void	handle_char(va_list *list, int *total_printed);
void	handle_string(va_list *list, int *total_printed);
void	handle_pointer(va_list *list, int *total_printed);
void	handle_number(va_list *list, int *total_printed);
void	handle_unsigned(va_list *list, int *total_printed);
void	handle_hex(va_list *list, int *total_printed, int uppercase);
void	handle_percent(int *total_printed);
# endif