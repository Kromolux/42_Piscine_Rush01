/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshahin <hshahin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:26:44 by rkaufman          #+#    #+#             */
/*   Updated: 2021/10/10 23:27:15 by hshahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**allocate_mem(void)
{
	char	**map;
	int		i;

	map = (char **) malloc(sizeof(char *) * 6);
	i = 0;
	while (i < 6)
	{
		map[i] = (char *) malloc(sizeof(char) * 6);
		i++;
	}
	return (map);
}
