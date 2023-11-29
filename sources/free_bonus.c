/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:49:43 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/29 14:00:56 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ffree(void *p)
{
	if (p)
		free(p);
	p = NULL;
}

void	mlx_free(t_data *data)
{
	if (data->tex->no && data->tex->no->img)
		mlx_destroy_image(data->mlx, data->tex->no->img);
	if (data->tex->so && data->tex->so->img)
		mlx_destroy_image(data->mlx, data->tex->so->img);
	if (data->tex->ea && data->tex->ea->img)
		mlx_destroy_image(data->mlx, data->tex->ea->img);
	if (data->tex->we && data->tex->we->img)
		mlx_destroy_image(data->mlx, data->tex->we->img);
	if (data->tex->door && data->tex->door->img)
		mlx_destroy_image(data->mlx, data->tex->door->img);
	if (data->tex->door1 && data->tex->door1->img)
		mlx_destroy_image(data->mlx, data->tex->door1->img);
	if (data->tex->door2 && data->tex->door2->img)
		mlx_destroy_image(data->mlx, data->tex->door2->img);
	if (data->tex->door3 && data->tex->door3->img)
		mlx_destroy_image(data->mlx, data->tex->door3->img);
	if (data->img && data->img->img)
		mlx_destroy_image(data->mlx, data->img->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}

void	free_tex(t_data *data)
{
	ffree(data->tex->door);
	ffree(data->tex->door1);
	ffree(data->tex->door2);
	ffree(data->tex->door3);
	ffree(data->tex->fl);
	ffree(data->tex->ce);
	ffree(data->tex->no);
	ffree(data->tex->ea);
	ffree(data->tex->we);
	ffree(data->tex->so);
	ffree(data->tex);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	mlx_free(data);
	free_tex(data);
	ffree(data->player);
	ffree(data->ray);
	ffree(data->img);
	while (data->file[i])
	{
		ffree(data->file[i]);
		i++;
	}
	ffree(data->file);
	ffree(data->mlx);
	ffree(data);
	exit (0);
}
