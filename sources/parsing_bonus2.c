/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:43:15 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/30 15:11:00 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_door(t_data *data, int i)
{
	if (ft_strcmp(data->file[i], "DO "))
		check_tex(data, data->file[i], "do");
	else if (ft_strcmp(data->file[i], "D1 "))
		check_tex(data, data->file[i], "d1");
	else if (ft_strcmp(data->file[i], "D2 "))
		check_tex(data, data->file[i], "d2");
	else if (ft_strcmp(data->file[i], "D3 "))
		check_tex(data, data->file[i], "d3");
}

bool	check_all_bonus(t_data *data)
{
	if (data->cm)
		return (printf("Error\nMap should be last arg of the file\n"), TRUE);
	if (!data->tex->no)
		return (printf("Error\nNo texture for North\n"), TRUE);
	if (!data->tex->so)
		return (printf("Error\nNo texture for South\n"), TRUE);
	if (!data->tex->we)
		return (printf("Error\nNo texture for West\n"), TRUE);
	if (!data->tex->ea)
		return (printf("Error\nNo texture for East\n"), TRUE);
	if (!data->tex->door || !data->tex->door1
		|| !data->tex->door2 || !data->tex->door3)
		return (printf("Error\nNo texture for Door\n"), TRUE);
	if (check_rgb(data->tex->fl))
		return (printf("Error\nNo rgb for the Floor\n"), TRUE);
	if (check_rgb(data->tex->ce))
		return (printf("Error\nNo rgb for the Ceiling\n"), TRUE);
	if (!data->map)
		return (TRUE);
	do_wh_map(data);
	return (FALSE);
}

bool	check_file(t_data *data, int i)
{
	while (data->file[++i])
	{
		if (ft_strcmp(data->file[i], "NO "))
			check_tex(data, data->file[i], "no");
		else if (ft_strcmp(data->file[i], "SO "))
			check_tex(data, data->file[i], "so");
		else if (ft_strcmp(data->file[i], "WE "))
			check_tex(data, data->file[i], "we");
		else if (ft_strcmp(data->file[i], "EA "))
			check_tex(data, data->file[i], "ea");
		else if (ft_strcmp(data->file[i], "D"))
			check_door(data, i);
		else if (ft_strcmp(data->file[i], "F "))
			check_fc(data, data->file[i]);
		else if (ft_strcmp(data->file[i], "C "))
			check_fc(data, data->file[i]);
		else if (check_map(&data->file[i], data) && !data->cm)
		{
			if (!map_error_controler(&data->file[i], data))
				data->map = &data->file[i];
			break ;
		}
	}
	return (check_all_bonus(data));
}
