/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:43:30 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/28 15:56:21 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_value_for_x(t_data *data, int x)
{
	data->ray->fov = M_PI / 2;
	data->ray->camerax = 2 * x / (double)WIDTH - 1;
	data->ray->rayangle = atan2(data->player->dy, data->player->dx)
		+ atan((x - WIDTH / 2.0) / (0.5 * WIDTH / tan(data->ray->fov / 2.0)));
	data->ray->raydiry = sin(data->ray->rayangle);
	data->ray->raydirx = cos(data->ray->rayangle);
	data->ray->deltadistx = fabs(1 / data->ray->raydirx);
	data->ray->deltadisty = fabs(1 / data->ray->raydiry);
	data->ray->hit = 0;
	data->ray->mapx = (int)data->player->x;
	data->ray->mapy = (int)data->player->y;
}

void	stepin(t_data *data)
{
	if (data->ray->sidedistx < data->ray->sidedisty)
	{
		data->ray->sidedistx += data->ray->deltadistx;
		data->ray->mapx += data->ray->stepx;
		data->ray->side = 0;
	}
	else
	{
		data->ray->sidedisty += data->ray->deltadisty;
		data->ray->mapy += data->ray->stepy;
		data->ray->side = 1;
	}
}

void	stepxstepy(t_data *data)
{
	if (data->ray->raydirx < 0)
	{
		data->ray->stepx = -1;
		data->ray->sidedistx = (data->player->x
				- data->ray->mapx) * data->ray->deltadistx;
	}
	else
	{
		data->ray->stepx = 1;
		data->ray->sidedistx = (data->ray->mapx
				+ 1.0 - data->player->x) * data->ray->deltadistx;
	}
	if (data->ray->raydiry < 0)
	{
		data->ray->stepy = -1;
		data->ray->sidedisty = (data->player->y
				- data->ray->mapy) * data->ray->deltadisty;
	}
	else
	{
		data->ray->stepy = 1;
		data->ray->sidedisty = (data->ray->mapy
				+ 1.0 - data->player->y) * data->ray->deltadisty;
	}
}

void	whithit(t_data *data, int x)
{
	double	angle;

	while (!data->ray->hit)
	{
		stepin(data);
		angle = atan2(data->player->dy, data->player->dx);
		if (data->map[data->ray->mapy][data->ray->mapx] != '0')
			check_hit(data);
		if (data->ray->side == 0)
			data->ray->perpwalldist = data->ray->sidedistx
				- data->ray->deltadistx;
		else
			data->ray->perpwalldist = data->ray->sidedisty
				- data->ray->deltadisty;
		data->ray->lineheight = (int)((HEIGHT / 2)
				/ cos(data->ray->rayangle - angle) / data->ray->perpwalldist);
		data->ray->drawstart = -data->ray->lineheight / 2 + HEIGHT / 2;
		data->ray->drawend = data->ray->lineheight / 2 + HEIGHT / 2;
		if (data->map[data->ray->mapy][data->ray->mapx] >= '1'
			&& data->map[data->ray->mapy][data->ray->mapx] <= '5')
			draw_line(data, x, data->ray->drawstart,
				data->ray->drawend);
	}
}

void	raycast(t_data *data)
{
	int		x;
	double	angle2;

	x = 0;
	while (x < WIDTH)
	{
		set_value_for_x(data, x);
		stepxstepy(data);
		whithit(data, x);
		angle2 = atan2(data->ray->raydiry, data->ray->raydirx);
		if (data->minimap)
			draw_ray_on_minimap(data, angle2, 0x9E9E9E);
		x++;
	}
	if (data->minimap)
		do_map(data, 0, 0);
}
