/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshahin <hshahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:20:24 by hshahin           #+#    #+#             */
/*   Updated: 2021/10/11 00:30:01 by hshahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (y <= 5)
	{
		x = 0;
		while (x <= 5)
		{
			map[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	assign_outer_numbers(char **map, char **argv)
{
	int	x;
	int	y;

	x = 1;
	while (x <= 4)
	{
		map[0][x] = argv[1][(x - 1) * 2] - '0';
		map[5][x] = argv[1][(x - 1) * 2 + 8] - '0';
		x++;
	}
	y = 1;
	while (y <= 4)
	{
		map[y][0] = argv[1][(y - 1) * 2 + 16] - '0';
		map[y][5] = argv[1][(y - 1) * 2 + 24] - '0';
		y++;
	}
}

void	print_map(char **map, int start_at, int end_at)
{
	int		y;
	int		x;
	char	c;

	y = start_at;
	while (y <= end_at)
	{
		x = start_at;
		while (x <= end_at)
		{
			c = map[y][x] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
