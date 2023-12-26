/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:50:55 by lteng             #+#    #+#             */
/*   Updated: 2023/12/26 12:14:58 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>

void print_data(void *data)
{
    printf("%s\n", (char *)data);
}

int main()
{
    // Example linked list creation
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));

    node1->data = "Hello";
    node1->next = node2;

    node2->data = "World";
    node2->next = NULL;

    // Applying the function to each element of the linked list
    ft_list_foreach(node1, print_data);

    // Remember to free allocated memory
    free(node1);
    free(node2);

    return 0;
}
*/
