/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:52:18 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/20 16:52:19 by agiguair         ###   ########.fr       */
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

void do_square(t_data *data, int cppw, int cpph, int x ,int y, int k)
{
	int i;
	int j;

	i = cppw / 4 ;
	while (i < cppw)
	{
		j = -cpph / 4;
		while (j < cpph)
		{
				my_mlx_pixel_put(data, x + i, y + j, k);
			j++;
		}
		i++;
	}
}

void	set_on_map_player(t_data *data, int cppw, int cpph)
{
	if (data->player->dx == 1 && data->player->dy == 0)
		do_square(data, cppw, cpph, round(data->player->x * cpph), round(data->player->y * cppw), 7929738);
	if (data->player->dx == -1 && data->player->dy == 0)
		do_square(data, cppw, cpph, round(data->player->x * cpph), round(data->player->y * cppw), 16775956);
	if (data->player->dx == 0 && data->player->dy == 1)
		do_square(data, cppw, cpph, round(data->player->x * cpph), round(data->player->y * cppw), 16711680);
	if (data->player->dx == 0 && data->player->dy == -1)
		do_square(data, cppw, cpph, round(data->player->x * cpph), round(data->player->y * cppw), 5130239);

}

void	do_map(t_data *data)
{
	int cppw;
	int	cpph;
	int	x;
	int y;
	int	i;
	int	j;


	cpph = round(WIDTH / data->w_map);
	cppw = round(HEIGHT / data->h_map);
	i = 0;
	y = 1;
	while (data->map[i])
	{
		j = 0;
		x = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
			{
				do_square(data, cppw, cpph, x, y, 16777215);
			}
			x += cpph;
			j++;
		}
		y += cppw;
		i++;
	}
	set_on_map_player(data, cppw, cpph);
}

void	clear_map(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(data, x, y , 0);
			x++;
		}
		y++;
	}
}
