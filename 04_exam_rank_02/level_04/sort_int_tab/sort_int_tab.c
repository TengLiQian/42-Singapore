/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:03:07 by lteng             #+#    #+#             */
/*   Updated: 2023/12/26 17:57:10 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	int				temp;
	unsigned int	i;

	temp = 0;
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}
/*
int	main(void)
{
	int				test_array[] = {5, 2, 8, 1, 3};
	unsigned int	array_size = sizeof(test_array) / sizeof(test_array[0]);

	printf("Original Array: ");
	for (unsigned int i = 0; i < array_size; i++)
		printf("%d ", test_array[i]);

	sort_int_tab(test_array, array_size);

	printf("Sorted Array: ");
	for (unsigned int i = 0; i < array_size; i++)
		printf("%d ", test_array[i]);
}*/
