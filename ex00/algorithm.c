/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshahin <hshahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:26:11 by hshahin           #+#    #+#             */
/*   Updated: 2021/10/10 23:56:57 by hshahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	write_1234_row(char **map, int start, int y);
void	write_1234_column(char **map, int start, int x);

void	look_for_4(char **map)
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		if (map[0][i] == 4)
		{
			write_1234_column(map, 1, i);
		}
		if (map[5][i] == 4)
		{
			write_1234_column(map, 4, i);
		}
		if (map[i][0] == 4)
		{
			write_1234_row(map, 1, i);
		}
		if (map[i][5] == 4)
		{
			write_1234_row(map, 4, i);
		}
		i++;
	}
}

void	look_for_1(char **map)
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		if (map[0][i] == 1)
		{
			map[1][i] = 4;
		}
		if (map[5][i] == 1)
		{
			map[4][i] = 4;
		}
		if (map[i][0] == 1)
		{
			map[i][1] = 4;
		}
		if (map[i][5] == 1)
		{
			map[i][4] = 4;
		}
		i++;
	}
}

void	write_1234_row(char **map, int start, int y)
{
	int	i;

	if (start == 1)
	{
		i = 1;
		while (i <= 4)
		{
			map[y][i] = (char) i;
			i++;
		}
	}
	else if (start == 4)
	{
		i = 1;
		while (i <= 4)
		{
			map[y][i] = (char)(start + 1) - i;
			i++;
		}
	}
}

void	write_1234_column(char **map, int start, int x)
{
	int	i;

	if (start == 1)
	{
		i = 1;
		while (i <= 4)
		{
			map[i][x] = (char) i;
			i++;
		}
	}
	else if (start == 4)
	{
		i = 1;
		while (i <= 4)
		{
			map[i][x] = (char)(start + 1) - i;
			i++;
		}
	}
}

void	look_for_3(char **map)
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		if (map[0][i] == 3)
		{
			map[3][i] = 4;
		}
		if (map[5][i] == 3)
		{
			map[2][i] = 4;
		}
		if (map[i][0] == 3)
		{
			map[i][3] = 4;
		}
		if (map[i][5] == 3)
		{
			map[i][2] = 4;
		}
		i++;
	}
}
