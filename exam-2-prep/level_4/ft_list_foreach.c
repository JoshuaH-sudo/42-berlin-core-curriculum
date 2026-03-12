/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoban <jhoban@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:15:38 by jhoban            #+#    #+#             */
/*   Updated: 2026/03/12 20:18:04 by jhoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        f(begin_list->data);
        begin_list = begin_list->next;
    }
}

// test function
#include <stdio.h>
int main() {
    t_list node3 = {NULL, "Node 3"};
    t_list node2 = {&node3, "Node 2"};
    t_list node1 = {&node2, "Node 1"};

    ft_list_foreach(&node1, (void (*)(void *))printf);
}