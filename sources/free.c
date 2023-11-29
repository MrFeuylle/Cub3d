/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:49:43 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/29 12:38:09 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_free(t_data *data)
{
	if (data->tex->no->img)
		mlx_destroy_image(data->mlx, data->tex->no->img);
	if (data->tex->so->img)
		mlx_destroy_image(data->mlx, data->tex->so->img);
	if (data->tex->ea->img)
		mlx_destroy_image(data->mlx, data->tex->ea->img);
	if (data->tex->we->img)
		mlx_destroy_image(data->mlx, data->tex->we->img);
	if (data->tex->door && data->tex->door->img)
		mlx_destroy_image(data->mlx, data->tex->door->img);
	if (data->tex->door1 && data->tex->door1->img)
		mlx_destroy_image(data->mlx, data->tex->door1->img);
	if (data->tex->door2 && data->tex->door2->img)
		mlx_destroy_image(data->mlx, data->tex->door2->img);
	if (data->tex->door3 && data->tex->door3->img)
		mlx_destroy_image(data->mlx, data->tex->door3->img);
	if (data->img->img)
		mlx_destroy_image(data->mlx, data->img->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}

void	free_all2(t_data *data)
{
	if (data->tex->fl)
		free(data->tex->fl);
	if (data->tex->ce)
		free(data->tex->ce);
	if (data->tex->no)
		free(data->tex->no);
	if (data->tex->ea)
		free(data->tex->ea);
	if (data->tex->we)
		free(data->tex->we);
	if (data->tex->so)
		free(data->tex->so);
	if (data->tex)
		free(data->tex);
	if (data->player)
		free(data->player);
	if (data->ray)
		free(data->ray);
	if (data->img)
		free(data->img);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	mlx_free(data);
	free_all2(data);
	while (data->file[i])
	{
		free(data->file[i]);
		i++;
	}
	if (data->file)
		free(data->file);
	if (data->mlx)
		free(data->mlx);
	if (data)
		free(data);
	exit (0);
}
