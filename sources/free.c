/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:49:43 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/20 18:50:38 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_free(t_data *data)
{
	mlx_destroy_image(data->mlx, data->tex->no->img);
	mlx_destroy_image(data->mlx, data->tex->so->img);
	mlx_destroy_image(data->mlx, data->tex->ea->img);
	mlx_destroy_image(data->mlx, data->tex->we->img);
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	free(data->tex->ce);
	free(data->tex->fl);
	mlx_free(data);
	free(data->tex->no);
	free(data->tex->ea);
	free(data->tex->we);
	free(data->tex->so);
	free(data->tex);
	free(data->player);
	free(data->ray);
	free(data->img);
	while (data->file[i])
	{
		free(data->file[i]);
		i++;
	}
	free(data->file);
	free(data->mlx);
	free(data);
	exit (0);
}
