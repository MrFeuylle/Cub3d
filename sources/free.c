/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:49:43 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/17 06:05:39 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	free(data->tex->ce);
	free(data->tex->fl);
	mlx_destroy_image(data->mlx, data->tex->no);
	mlx_destroy_image(data->mlx, data->tex->so);
	mlx_destroy_image(data->mlx, data->tex->ea);
	mlx_destroy_image(data->mlx, data->tex->we);
	mlx_destroy_window(data->mlx, data->win);
	free(data->tex);
	free(data->player);
	while (data->file[i])
	{
		free(data->file[i]);
		i++;
	}
	free(data->file);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit (0);
}
