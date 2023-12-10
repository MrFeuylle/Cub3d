/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:48:37 by agiguair          #+#    #+#             */
/*   Updated: 2023/12/08 16:16:49 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_no_event(t_data *data)
{
	usleep(16666);
	mouse_hook(data);
	mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	if (data->rl == 1 || data->rr)
		view_player(data);
	if (data->mf == 1 || data->mb == 1)
		move_playerf(data);
	if (data->ml == 1 || data->mr == 1)
		move_playerlr(data);
	if (data->op == 3)
	{
		openingdoor(data);
		data->op = 0;
	}
	else
		data->op++;
	if (data->opdo)
		open_door(data);
	clear_map(data);
	do_floor_cel(data);
	raycast(data);
	data->opdo = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

void	toogle_minimap(t_data *data)
{
	if (data->minimap)
		data->minimap = 0;
	else
		data->minimap = 1;
}

int	key_press(int keysym, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (keysym == 32)
		data->opdo = 0;
	if (keysym == 109)
		toogle_minimap(data);
	if (keysym == 65361)
		data->rl = 1;
	if (keysym == 65363)
		data->rr = 1;
	if (keysym == 115)
		data->mf = 1;
	if (keysym == 119)
		data->mb = 1;
	if (keysym == 97)
		data->ml = 1;
	if (keysym == 100)
		data->mr = 1;
	if (keysym == XK_Escape)
		free_all(data);
	return (0);
}

int	key_release(int keysym, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (keysym == 32)
		data->opdo = 1;
	if (keysym == 65361)
		data->rl = 0;
	if (keysym == 65363)
		data->rr = 0;
	if (keysym == 119)
		data->mb = 0;
	if (keysym == 115)
		data->mf = 0;
	if (keysym == 97)
		data->ml = 0;
	if (keysym == 100)
		data->mr = 0;
	return (0);
}

int	cross_kill(t_data *data)
{
	free_all(data);
	return (0);
}
