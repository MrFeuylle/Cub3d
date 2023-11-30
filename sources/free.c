/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:49:43 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/30 12:13:31 by agiguair         ###   ########.fr       */
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
	if (data->img && data->img->img)
		mlx_destroy_image(data->mlx, data->img->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}

void	free_all2(t_data *data)
{
	ffree(data->tex->fl);
	ffree(data->tex->ce);
	ffree(data->tex->no);
	ffree(data->tex->ea);
	ffree(data->tex->we);
	ffree(data->tex->so);
	ffree(data->tex);
	ffree(data->player);
	ffree(data->ray);
	ffree(data->img);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	mlx_free(data);
	free_all2(data);
	while (data->file && data->file[i])
	{
		ffree(data->file[i]);
		i++;
	}
	ffree(data->file);
	ffree(data->mlx);
	ffree(data);
	exit (0);
}
