/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:54:16 by lteng             #+#    #+#             */
/*   Updated: 2023/12/04 21:20:36 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_number(int a)
{
	char	*str;
	char	i;

	str = "0123456789";
	if (a < 10)
	{
		i = str[a];
		write(1, &i, 1);
	}
	else
	{
		write_number(a / 10);
		write_number(a % 10);
	}
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (i % 3 == 0)
			write(1, "fizz\n", 5);
		else if (i % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			write_number(i);
			write(1, "\n", 1);
		}
		i++;
	}
}
