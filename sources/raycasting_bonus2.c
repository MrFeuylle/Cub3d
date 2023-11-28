/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:53:55 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/28 16:14:47 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_hit(t_data *data)
{
	if (data->map[data->ray->mapy][data->ray->mapx] == '1')
		data->ray->hit = 1;
	else if (data->map[data->ray->mapy][data->ray->mapx] == '2')
		data->ray->hit = 2;
	else if (data->map[data->ray->mapy][data->ray->mapx] == '3')
		data->ray->hit = 3;
	else if (data->map[data->ray->mapy][data->ray->mapx] == '4')
		data->ray->hit = 4;
	else if (data->map[data->ray->mapy][data->ray->mapx] == '5')
			data->ray->hit = 5;
	else if (data->map[data->ray->mapy][data->ray->mapx] == '7')
			data->ray->hit = 7;
	else if (data->map[data->ray->mapy][data->ray->mapx] == '8')
			data->ray->hit = 8;
	else if (data->map[data->ray->mapy][data->ray->mapx] == '9')
			data->ray->hit = 9;
}
