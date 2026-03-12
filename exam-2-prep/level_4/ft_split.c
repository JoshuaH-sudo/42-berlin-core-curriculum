/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:57:26 by jhoban            #+#    #+#             */
/*   Updated: 2026/03/12 20:08:40 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char **ft_split(char *str)
{
    int strIndex = 0;
    int wordIndex = 0;
    int wordStrIndex = 0;
    char **result = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1));

    while(str[strIndex])
    {
        while(str[strIndex] != ' ')
        {
            result[wordIndex][wordStrIndex] = str[strIndex];
            strIndex++;
            wordStrIndex++;
        }
        result[wordIndex][wordStrIndex] = '\0';
        wordIndex++;
        if (str[strIndex] == ' ')
            strIndex++;
    }
    result[wordIndex] = NULL;
    return (result); 
}