/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:18:05 by lteng             #+#    #+#             */
/*   Updated: 2023/12/07 16:39:16 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	result;

	result = 0;
	if (argc == 4)
	{
		i = atoi(argv[1]);
		j = atoi(argv[3]);
		if (argv[2][0] == '+')
			result = i + j;
		else if (argv[2][0] == '-')
			result = i - j;
		else if (argv[2][0] == '*')
			result = i * j;
		else if (argv[2][0] == '/')
			result = i / j;
		else if (argv[2][0] == '%')
			result = i % j;
		printf("%i", result);
	}
	else
		write(1, "\n", 1);
	return (0);
}
