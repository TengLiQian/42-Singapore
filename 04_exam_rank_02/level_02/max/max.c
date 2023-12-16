/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:18:51 by lteng             #+#    #+#             */
/*   Updated: 2023/12/14 12:27:17 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	max_num;
	int	i;

	max_num = 0;
	i = 0;
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (tab[i] > max_num)
			max_num = tab[i];
		i++;
	}
	return (max_num);
}
/*
int	main(void)
{
	int	arr1[] = {1, 2, 3, 8, 15, 4};
	printf("%i\n", max(arr1, 6));
	return (0);
}*/
