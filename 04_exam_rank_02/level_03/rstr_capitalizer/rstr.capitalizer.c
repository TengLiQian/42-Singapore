/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr.capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:20:50 by lteng             #+#    #+#             */
/*   Updated: 2023/12/22 15:49:38 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void char_convert(char a, char b)
{
	char new_char;

	if (a >= 'A' && a <= 'Z' && (b != ' ' && b != '\t' && b != '\0'))
	{
		new_char = a + 32;
		write(1, &new_char, 1);
	}
	else if (a >= 'a' && a <= 'z' && (b == ' ' || b == '\t' || b == '\0'))
	{
		new_char = a - 32;
		write(1, &new_char, 1);
	}
	else
		write(1, &a, 1);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argc >= 2 && i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			char_convert(argv[i][j], argv[i][j + 1]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	if (argc < 2)
		write(1, "\n", 1);
	return (0);
}
