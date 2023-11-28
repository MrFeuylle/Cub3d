/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:58:21 by jlarue            #+#    #+#             */
/*   Updated: 2023/11/28 16:34:18 by agiguair         ###   ########.fr       */
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
		[(int)(data->player->x + 1)] == '6')
			data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)]++;
	else if (data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)] == '6')
			data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)]++;
	else if (data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)] == '6')
			data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)]++;
	else if (data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)] == '6')
			data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)]++;
}

void	if_nine_to_two(t_data *data)
{
	if (data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)] == '9')
			data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)] = '2';
	else if (data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)] == '9')
			data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)] = '2';
	else if (data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)] == '9')
			data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)] = '2';
	else if (data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)] == '9')
			data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)] = '2';
}

void	closingdoor(t_data *data)
{
	if_nine_to_two(data);
	if (data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)] >= '7' &&
		data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)] < '9')
			data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)]++;
	else if (data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)] >= '7' &&
		data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)] < '9')
			data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)]++;
	else if (data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)] >= '7' &&
		data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)] < '9')
			data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)]++;
	else if (data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)] >= '7' &&
		data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)] < '9')
			data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)]++;
}

void	openingdoor(t_data *data)
{
	if (data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)] >= '3' &&
		data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)] < '6')
			data->map[(int)(data->player->y)]
		[(int)(data->player->x + 1)]++;
	else if (data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)] >= '3' &&
		data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)] < '6')
			data->map[(int)(data->player->y + 1)]
		[(int)(data->player->x)]++;
	else if (data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)] >= '3' &&
		data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)] < '6')
			data->map[(int)(data->player->y)]
		[(int)(data->player->x - 1)]++;
	else if (data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)] >= '3' &&
		data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)] < '6')
			data->map[(int)(data->player->y - 1)]
		[(int)(data->player->x)]++;
	closingdoor(data);
}
