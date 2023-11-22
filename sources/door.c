/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:58:21 by jlarue            #+#    #+#             */
/*   Updated: 2023/11/22 16:58:47 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	open_door(t_data *data)
{
	if (data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)] == '2')
			data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)] = '3';
	else if (data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)] == '2')
			data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)] = '3';
	else if (data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)] == '2')
			data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)] = '3';
	else if (data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)] == '2')
			data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)] = '3';
	else
		close_door(data);
}

void	close_door(t_data *data)
{
	if (data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)] == '3')
			data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)] = '2';
	else if (data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)] == '3')
			data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)] = '2';
	else if (data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)] == '3')
			data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)] = '2';
	else if (data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)] == '3')
			data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)] = '2';
}
