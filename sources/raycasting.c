/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:43:30 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/20 23:31:59 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_line(t_data *data, int x, int y1, int y2)
{
	int			y;
	t_rgb		rgb;
	int			tex_y;
	int			tex_offset;
	t_texture	*texture;

	y = y1;
	texture = data->tex->so;
	while (y <= y2)
	{
		tex_y = (y - y1) * texture->height / (y2 - y1 + 1);
		tex_offset = tex_y * texture->line_length
			+ x * (texture->bits_per_pixel / 8);
		rgb.red = (unsigned char)texture->addr[tex_offset + 2];
		rgb.green = (unsigned char)texture->addr[tex_offset + 1];
		rgb.blue = (unsigned char)texture->addr[tex_offset];
		my_mlx_pixel_put(data, x, y, rgb_to_int(&rgb));
		y++;
	}
}

void	set_value_for_x(t_data *data, int x)
{
	data->ray->fov = M_PI / 4;
	data->ray->camerax = 2 * x / (double)WIDTH - 1;
	data->ray->raydiry = data->player->dy
		* data->ray->camerax * sin(data->ray->fov / 2);
	data->ray->raydirx = data->player->dx
		* data->ray->camerax * sin(data->ray->fov / 2);
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
		if (data->map[data->ray->mapy][data->ray->mapx] == '1')
			data->ray->hit = 1;
		if (data->ray->side == 0)
			data->ray->perpwalldist = (data->ray->sidedistx
					- data->ray->deltadistx * cos(data->ray->camerax - angle));
		else
			data->ray->perpwalldist = (data->ray->sidedisty
					- data->ray->deltadisty * cos(data->ray->camerax - angle));
		data->ray->lineheight = (int)(HEIGHT / data->ray->perpwalldist);
		data->ray->drawstart = -data->ray->lineheight / 2 + HEIGHT / 2;
		if (data->ray->drawstart < 0)
			data->ray->drawstart = 0;
		data->ray->drawend = data->ray->lineheight / 2 + HEIGHT / 2;
		if (data->ray->drawend >= HEIGHT)
			data->ray->drawend = HEIGHT - 1;
		if (data->map[data->ray->mapy][data->ray->mapx] == '1')
			draw_line(data, x, data->ray->drawstart,
				data->ray->drawend);
	}
}

void	raycast(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		set_value_for_x(data, x);
		stepxstepy(data);
		whithit(data, x);
		x++;
	}
}
