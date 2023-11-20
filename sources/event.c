/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:48:37 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/20 18:03:49 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_no_event(void *data)
{
	(void) data;
	return (0);
}

int	get_arrow(t_data *data, int keysym)
{
	double	old;
	if (keysym == 65361)
	{
		old = data->player->dx;
		data->player->dx = data->player->dx * cos(360) - data->player->dy * sin(360);
		data->player->dy = old * sin(360) + data->player->dy * cos(360);
	}
	if (keysym == 65363)
	{
		old = data->player->dx;
		data->player->dx = data->player->dx * cos(1) - data->player->dy * sin(1);
		data->player->dy = old * sin(1) + data->player->dy * cos(1);
	}
	if (ft_abs(data->player->dx) > 1)
		data->player->dx = 0;
	if (ft_abs(data->player->dy) > 1)
		data->player->dy = 0;
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		free_all(data);
	if (keysym == 119)
	{
		if (data->map[(int)(data->player->y)][(int)(data->player->x + data->player->dx * 1)] != '1')
			data->player->x += data->player->dx * 1;
		if (data->map[(int)(data->player->y + data->player->dy * 1)][(int)(data->player->x)] != '1')
			data->player->y += data->player->dy * 1;
	}
	if (keysym == 115)
	{
		if (data->map[(int)(data->player->y)][(int)(data->player->x - data->player->dx * 1)] != '1')
			data->player->x -= data->player->dx * 1;
		if (data->map[(int)(data->player->y - data->player->dy * 1)][(int)(data->player->x)] != '1')
			data->player->y -= data->player->dy * 1;
	}
	get_arrow(data, keysym);
	clear_map(data);
	// do_map(data);
	do_floor_cel(data);
	raycast(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

int	cross_kill(t_data *data)
{
	free_all(data);
	return (0);
}
