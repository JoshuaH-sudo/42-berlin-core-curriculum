/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:11:16 by jhoban            #+#    #+#             */
/*   Updated: 2025/11/19 16:40:46 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convert(int nb, char *str, int start)
{
	int		mod;

	if (nb != 0)
	{
		mod = nb % 10;
		nb = nb / 10;
		convert(nb, str, start - 1);
		if (mod < 0)
			mod = 0 - mod;
		str[start] = (char)(mod + '0');
	}
  return str;
}

int count_digits(int n)
{
  int	count;

  count = 0;
  if (n <= 0)
    count++;
  while (n != 0)
  {
    n = n / 10;
    count++;
  }
  return (count);
}

char  *ft_itoa(int n)
{
  char  *str;
  int   digits;
  int   is_negative;

  if (n == 0)
  {
    str = ft_calloc(2, sizeof(char));
    if (!str)
      return (NULL);
    str[0] = '0';
    str[1] = '\0';
    return (str);
  }

  if (n < 0)
    is_negative = 1;
  else
    is_negative = 0;
  
  digits = count_digits(n) + is_negative;
  str = ft_calloc(digits + 1, sizeof(char));

  if (!str)
    return (NULL);
  if (is_negative)
    str[0] = '-';

  str = convert(n, str, digits - 1 - is_negative);
  str[digits] = '\0';
  
  return (str);
}