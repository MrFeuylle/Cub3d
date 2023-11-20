/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:48:37 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/20 22:44:39 by agiguair         ###   ########.fr       */
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
		angle = 5;
		radian_angle = angle * M_PI / 180.0;
		data->player->dx = data->player->dx
			* cos(radian_angle) - data->player->dy * sin(radian_angle);
		data->player->dy = old_dx * sin(radian_angle)
			+ data->player->dy * cos(radian_angle);
	}
	if (data->rr == 1)
	{
		angle = -5;
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
		[(int)(data->player->x + data->player->dx * 0.1)] != '1')
			data->player->x += data->player->dx * 0.1;
		if (data->map[(int)(data->player->y + data->player->dy * 0.1)]
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

int	handle_no_event(t_data *data)
{
	usleep(33333);
	if (data->rl == 1 || data->rr)
		view_player(data);
	if (data->mf == 1 || data->mb == 1)
		move_player(data);
	clear_map(data);
	do_floor_cel(data);
	raycast(data);
	// do_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

int	key_press(int keysym, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (keysym == 65361)
		data->rl = 1;
	if (keysym == 65363)
		data->rr = 1;
	if (keysym == 115)
		data->mf = 1;
	if (keysym == 119)
		data->mb = 1;
	if (keysym == XK_Escape)
		free_all(data);
	return (0);
}

int	key_release(int keysym, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (keysym == 65361)
		data->rl = 0;
	if (keysym == 65363)
		data->rr = 0;
	if (keysym == 119)
		data->mb = 0;
	if (keysym == 115)
		data->mf = 0;
	return (0);
}

int	cross_kill(t_data *data)
{
	free_all(data);
	return (0);
}
