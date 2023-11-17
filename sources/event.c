/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:48:37 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/17 06:17:35 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_no_event(void *data)
{
	(void) data;
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		free_all(data);
	if (keysym == 119)
	{
		data->player->x += data->player->dx * 0.1;
		data->player->y += data->player->dy * 0.1;
	}
	if (keysym == 97)
	{
		data->player->y += data->player->dx * 0.1;
		data->player->x += data->player->dy * 0.1;
	}
	if (keysym == 115)
	{
		data->player->x -= data->player->dx * 0.1;
		data->player->y -= data->player->dy * 0.1;
	}
	if (keysym == 100)
	{
		data->player->y -= data->player->dx * 0.1;
		data->player->x -= data->player->dy * 0.1;
	}
	return (0);
}

int	cross_kill(t_data *data)
{
	free_all(data);
	return (0);
}
