/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:36:36 by lteng             #+#    #+#             */
/*   Updated: 2023/12/19 14:52:41 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int x)
{
	char	a;

	a = '0';
	if (x > 9)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else if (x <= 9)
	{
		a += x;
		write(1, &a, 1);
	}
}

int	main(int argc, char *argv[])
{
	int	common_denom;

	common_denom = 1;
	if (argc == 3 && atoi(argv[1]) > 0 && atoi(argv[2]) > 0)
	{
		if (atoi(argv[1]) > atoi(argv[2]))
			common_denom = atoi(argv[2]);
		else
			common_denom = atoi(argv[1]);
		while (common_denom > 0)
		{
			if (atoi(argv[1]) % common_denom == 0
				&& atoi(argv[2]) % common_denom == 0)
			{
				ft_putnbr(common_denom);
				break ;
			}
			common_denom -= 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}
