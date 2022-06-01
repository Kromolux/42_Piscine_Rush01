/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshahin <hshahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:07:16 by rkaufman          #+#    #+#             */
/*   Updated: 2021/10/11 01:23:29 by hshahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		check_input_arguments(int argc, char **argv);
char	**allocate_mem(void);
void	initialize_map(char **map);
void	look_for_4(char **map);
void	look_for_1(char **map);
void	look_for_3(char **map);
void	print_map(char **map, int start_at, int end_at);
int		solve_puzzle(char **map, int y, int x);
int		is_safe(char **map, int y, int x, int num);

void	assign_outer_numbers(char **map, char **argv);

int	main(int argc, char **argv)
{
	char	**map;

	if (check_input_arguments(argc, argv) == 1)
	{
		map = allocate_mem();
		if (map != NULL)
		{
			initialize_map(map);
			assign_outer_numbers(map, argv);
			look_for_4(map);
			look_for_1(map);
			solve_puzzle(map, 1, 1);
			print_map(map, 0, 5);
			free(map);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}

int	check_input_arguments(int argc, char **argv)
{
	int	output;
	int	i;

	output = -1;
	if (argc == 2)
	{
		i = 0;
		while (output == -1)
		{
			if (!(argv[1][i] >= '1' && argv[1][i] <= '4')
				|| (argv[1][i + 1] != ' ' && argv[1][i + 1] != '\0'))
			{
				output = 0;
			}
			else if (i == 30)
				output = 1;
			i += 2;
		}
	}
	else
	{
		output = 0;
	}
	return (output);
}
