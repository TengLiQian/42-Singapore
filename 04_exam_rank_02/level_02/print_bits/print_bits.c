/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:27:37 by lteng             #+#    #+#             */
/*   Updated: 2023/12/14 15:46:41 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((octet & (1 << i)) == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		i--;
	}
}
/*
int	main(void)
{
	print_bits(2);
	write(1, "\n", 1);
	return (0);
}*/