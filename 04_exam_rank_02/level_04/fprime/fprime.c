/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:13:32 by lteng             #+#    #+#             */
/*   Updated: 2023/12/25 15:05:09 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	nbr;

	i = 2;
	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		if (nbr == 1)
			printf("%i", nbr);
		while (nbr >= i)
		{
			if (nbr % i == 0)
			{
				printf("%i", i);
				if (nbr != i)
					printf("*");
				nbr /= i;
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
