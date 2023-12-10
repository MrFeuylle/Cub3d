/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:38:18 by agiguair          #+#    #+#             */
/*   Updated: 2023/12/10 14:57:55 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_texture	*get_texture(t_data *data)
{
	if (data->ray->hit == 2)
		return (data->tex->door);
	if (data->ray->hit == 3 || data->ray->hit == 9)
		return (data->tex->door1);
	if (data->ray->hit == 4 || data->ray->hit == 8)
		return (data->tex->door2);
	if (data->ray->hit == 5 || data->ray->hit == 7)
		return (data->tex->door3);
	if (data->ray->side)
	{
		if (data->ray->raydiry > 0)
			return (data->tex->so);
		else
			return (data->tex->no);
	}
	else
	{
		if (data->ray->raydirx > 0)
			return (data->tex->ea);
		else
			return (data->tex->we);
	}
}

void	set_ray_dl(t_data *data, t_texture *texture)
{
	if (data->ray->side == 0)
		data->ray->wallx = data->player->y
			+ data->ray->perpwalldist * data->ray->raydiry;
	else
		data->ray->wallx = data->player->x
			+ data->ray->perpwalldist * data->ray->raydirx;
	data->ray->wallx -= floor(data->ray->wallx);
	data->ray->texx = (int)(data->ray->wallx * (double)texture->width);
	if ((data->ray->side == 0 && data->ray->raydirx > 0)
		|| (data->ray->side == 1 && data->ray->raydiry < 0))
		data->ray->texx = texture->width - data->ray->texx - 1;
	data->ray->step = 1.0 * texture->height / data->ray->lineheight;
	data->ray->texpos = (data->ray->drawstart - HEIGHT / 2
			+ data->ray->lineheight / 2) * data->ray->step;
	data->ray->step = 1.0 * texture->height / data->ray->lineheight;
	data->ray->texx = texture->width - data->ray->texx - 1;
	data->ray->texpos = (data->ray->drawstart - HEIGHT / 2
			+ data->ray->lineheight / 2) * data->ray->step;
}

void	draw_line(t_data *data, int x, int y1, int y2)
{
	int			y;
	t_rgb		rgb;
	t_texture	*texture;

	y = y1;
	texture = get_texture(data);
	set_ray_dl(data, texture);
	while (y <= y2)
	{
		data->ray->texy = (int)data->ray->texpos & (texture->height - 1);
		data->ray->tex_offset = data->ray->texy * texture->line_length
			+ data->ray->texx * (texture->bits_per_pixel / 8);
		rgb.red = (unsigned char)texture->addr[data->ray->tex_offset + 2];
		rgb.green = (unsigned char)texture->addr[data->ray->tex_offset + 1];
		rgb.blue = (unsigned char)texture->addr[data->ray->tex_offset];
		my_mlx_pixel_put(data, x, y, rgb_to_int(&rgb));
		y++;
		data->ray->texpos += data->ray->step;
	}
}
