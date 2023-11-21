/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:52:18 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/21 09:09:07 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	char	*dst;

	if (x > 1920 || x < 0 || y > 1200 || y < 0)
		return ;
	dst = data->img->addr + ((int)round(y) * data->img->line_length
			+ (int)round(x) * (data->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	rgb_to_int(t_rgb *rgb)
{
	return (((rgb->red << 16) | (rgb->green << 8) | (rgb->blue)));
}

void	do_floor_cel(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y > HEIGHT / 2)
				my_mlx_pixel_put(data, x, y, rgb_to_int(data->tex->fl));
			else
				my_mlx_pixel_put(data, x, y, rgb_to_int(data->tex->ce));
			y++;
		}
		x++;
	}
}

void	do_square(t_data *data, int cppw, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < cppw)
	{
		j = 0;
		while (j < cppw)
		{
			my_mlx_pixel_put(data, x + i, y + j, 16777215);
			j++;
		}
		i++;
	}
}

void	set_on_map_player(t_data *data, int cppw)
{
	my_mlx_pixel_put(data, round(data->player->x * cppw),
		round(data->player->y * cppw), 7929738);
}
