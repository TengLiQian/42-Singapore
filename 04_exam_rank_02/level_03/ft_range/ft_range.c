/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:50:54 by lteng             #+#    #+#             */
/*   Updated: 2023/12/16 17:57:23 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_count(int x, int y)
{
	if (y < x)
		return (x - y + 1);
	return (y - x + 1);
}

int	*ft_range(int start, int end)
{
	int	*final;
	int	count;
	int	i;

	count = ft_count(start, end);
	i = 0;
	final = malloc(sizeof(int) * count);
	if (!final)
		return (NULL);
	while (start <= end && i < count)
	{
		final[i] = start + i;
		i++;
	}
	while (end <= start && i < count)
	{
		final[i] = start - i;
		i++;
	}
	return (final);
}
/*
int	main(void)
{
	int	start = 0;
	int	end = 0;
	int	*result1 = ft_range(start, end);
	int	i = 0;
	int	count = ft_count(start, end);
	while (i < count)
	{
		printf("%i", result1[i]);
		i++;
	}
	free(result1);
	return (0);
}*/
