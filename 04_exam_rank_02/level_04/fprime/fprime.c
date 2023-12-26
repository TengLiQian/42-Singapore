/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:13:32 by lteng             #+#    #+#             */
/*   Updated: 2023/12/26 11:17:21 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_isprime(int nbr)
{
	int	i;

	i = 2;
	if (nbr <= 1)
		return (0);
	while (i <= (nbr / 2))
	{
		if ((nbr % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print(int i, int nbr)
{
	printf("%i", i);
	if (nbr != i)
		printf("*");
}

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
			if (nbr % i == 0 && ft_isprime(i) == 1)
			{
				ft_print(i, nbr);
				while ((nbr /= i) % i == 0)
					ft_print(i, nbr);
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
