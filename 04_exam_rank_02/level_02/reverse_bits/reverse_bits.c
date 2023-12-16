/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:06:32 by lteng             #+#    #+#             */
/*   Updated: 2023/12/14 16:11:23 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	result;

	i = 8;
	result = 0;
	while (i > 0)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
		i--;
	}
	return (result);
}
/*
int	main(void)
{
	printf("%hhu\n", reverse_bits(0));
	return (0);
}*/
