/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:44:22 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/21 09:02:53 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	view_player(t_data *data)
{
	double	old_dx;
	double	angle;
	double	radian_angle;

	old_dx = data->player->dx;
	if (data->rl == 1)
	{
		angle = -5;
		radian_angle = angle * M_PI / 180.0;
		data->player->dx = data->player->dx
			* cos(radian_angle) - data->player->dy * sin(radian_angle);
		data->player->dy = old_dx * sin(radian_angle)
			+ data->player->dy * cos(radian_angle);
	}
	if (data->rr == 1)
	{
		angle = +5;
		radian_angle = angle * M_PI / 180.0;
		data->player->dx = data->player->dx * cos(radian_angle)
			- data->player->dy * sin(radian_angle);
		data->player->dy = old_dx * sin(radian_angle)
			+ data->player->dy * cos(radian_angle);
	}
}

void	move_player(t_data *data)
{
	if (data->mb)
	{
		if (data->map[(int)(data->player->y)]
		[(int)(data->player->x + data->player->dx * 0.3)] != '1')
			data->player->x += data->player->dx * 0.1;
		if (data->map[(int)(data->player->y + data->player->dy * 0.3)]
		[(int)(data->player->x)] != '1')
			data->player->y += data->player->dy * 0.1;
	}
	if (data->mf)
	{
		if (data->map[(int)(data->player->y)]
		[(int)(data->player->x - data->player->dx * 0.1)] != '1')
			data->player->x -= data->player->dx * 0.1;
		if (data->map[(int)(data->player->y - data->player->dy * 0.1)]
		[(int)(data->player->x)] != '1')
			data->player->y -= data->player->dy * 0.1;
	}
}
