/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:12:18 by lteng             #+#    #+#             */
/*   Updated: 2023/12/25 13:12:00 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	t_point	cur;

	cur = begin;
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y
		|| tab[cur.y][cur.x] == 'F' || tab[cur.y][cur.x] == '0')
		return ;
	else
		tab[cur.y][cur.x] = 'F';

	flood_fill(tab, size, (t_point){cur.x - 1, cur.y});
	flood_fill(tab, size, (t_point){cur.x + 1, cur.y});
	flood_fill(tab, size, (t_point){cur.x, cur.y - 1});
	flood_fill(tab, size, (t_point){cur.x, cur.y + 1});
}
