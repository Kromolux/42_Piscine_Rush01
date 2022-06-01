/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrakskyscraber.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshahin <hshahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:31:55 by hshahin           #+#    #+#             */
/*   Updated: 2021/10/11 01:11:55 by hshahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_not_safe(char **map, int y, int x, int num);

int	is_safe(char **map, int y, int x, int num)
{
	if (is_not_safe(map, y, x, num) == 0)
		return (0);
	if (num == 3)
	{
		if ((y == 1 && map[0][x] == 3) || (y == 4 && map[5][x] == 3)
			|| (x == 1 && map[y][0] == 3) || (x == 4 && map[y][5] == 3))
			return (0);
	}
	if (num == 1)
	{
		 if ((y == 2 && map[0][x] == 3) || (y == 3 && map[5][x] == 3)
			|| (x == 2 && map[y][0] == 3) || (x == 3 && map[x][5] == 3))
			return (0);
	}
	return (1);
}

int	is_not_safe(char **map, int y, int x, int num)
{
	int		i;

	i = 1;
	while (i <= 4)
	{
		if (map[y][i++] == num)
			return (0);
	}
	i = 1;
	while (i <= 4)
	{
		if (map[i++][x] == num)
			return (0);
	}
	return (1);
}

int	solve_puzzle(char **map, int y, int x)
{
	int		num;

	if (y == 4 && x == 4)
		return (1);
	if (x == 5)
	{
		y++;
		x = 1;
	}
	if (map[y][x] > 0)
		return (solve_puzzle(map, y, x + 1));
	num = 1;
	while (num <= 4)
	{
		if (is_safe(map, y, x, num) == 1)
		{
			map[y][x] = num;
			if (solve_puzzle(map, y, x + 1) == 1)
				return (1);
		}
		map[y][x] = 0;
		num++;
	}
	return (0);
}
