/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:19:42 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/21 11:47:43 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_size_scale(char **map)
{
	int	max_i;
	int	max_j;
	int	i;
	int	j;


	max_i = 0;
	max_j = 0;
	i = 0;
	while (map[i])
	{
		max_i = i;
		j = 0;
		while (map[i][j])
		{
			if (j > max_j)
				max_j = j;
			j++;
		}
		i++;
	}
	if (max_i > max_j)
		return ((max_i / 40) + 1);
	return ((max_j / 40) + 1);
}
