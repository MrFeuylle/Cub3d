/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:49:39 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/21 09:21:39 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_mini	*set_mini(t_data *data, double angle, t_mini *mini)
{
	mini->cppw = 10;
	mini->cpph = 10;
	mini->x1 = round(data->player->x * mini->cppw);
	mini->y1 = round(data->player->y * mini->cpph);
	mini->x2 = round((data->player->x + cos(angle)
				* data->ray->perpwalldist) * mini->cppw);
	mini->y2 = round((data->player->y + sin(angle)
				* data->ray->perpwalldist) * mini->cpph);
	mini->dx = abs(mini->x2 - mini->x1);
	mini->dy = abs(mini->y2 - mini->y1);
	if (mini->y1 < mini->y2)
		mini->sy = 1;
	else
		mini->sy = -1;
	if (mini->x1 < mini->x2)
		mini->sx = 1;
	else
		mini->sx = -1;
	mini->err = mini->dx - mini->dy;
	return (mini);
}

void	draw_ray_on_minimap(t_data *data, double angle, int color)
{
	t_mini	*mini;

	mini = malloc(sizeof(t_mini));
	mini = set_mini(data, angle, mini);
	while (1)
	{
		my_mlx_pixel_put(data, mini->x1, mini->y1, color);
		if (mini->x1 == mini->x2 && mini->y1 == mini->y2)
			break ;
		mini->e2 = 2 * mini->err;
		if (mini->e2 > -mini->dy)
		{
			mini->err -= mini->dy;
			mini->x1 += mini->sx;
		}
		if (mini->e2 < mini->dx)
		{
			mini->err += mini->dx;
			mini->y1 += mini->sy;
		}
	}
	free(mini);
}

void	draw_square_outline(t_data *data, int cppw, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < cppw)
	{
		my_mlx_pixel_put(data, x + i, y, 0);
		my_mlx_pixel_put(data, x + i, y + cppw - 1, 0);
		i++;
	}
	j = 0;
	while (j < cppw)
	{
		my_mlx_pixel_put(data, x, y + j, 0);
		my_mlx_pixel_put(data, x + cppw - 1, y + j, 0);
		j++;
	}
}

void	do_map(t_data *data)
{
	int	cpph;
	int	x;
	int	y;
	int	i;
	int	j;

	cpph = 10;
	i = -1;
	y = 0;
	while (data->map[++i])
	{
		j = -1;
		x = 0;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
			{
				do_square(data, cpph, x, y);
				draw_square_outline(data, cpph, x, y);
			}
			x += cpph;
		}
		y += cpph;
	}
	set_on_map_player(data, cpph);
}

void	clear_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(data, x, y, 0);
			x++;
		}
		y++;
	}
}
