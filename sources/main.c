/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:06:25 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/22 17:07:30 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_data	*init_data(t_data *data)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->tex = malloc(sizeof(t_tex));
	if (!data->tex)
		return (free(data), NULL);
	data->tex->fl = malloc(sizeof(t_rgb));
	if (!data->tex->fl)
		return (free(data->tex), free(data), NULL);
	data->tex->ce = malloc(sizeof(t_rgb));
	if (!data->tex->ce)
		return (free(data->tex->fl), free(data->tex), free(data), NULL);
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		return (free(data->tex->ce), free(data->tex->fl),
			free(data->tex), free(data), NULL);
	data->ray = malloc(sizeof(t_ray));
	if (!data->player)
		return (free(data->player), free(data->tex->ce),
			free(data->tex->fl), free(data->tex), free(data), NULL);
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		return (free(data->ray), free(data->player), free(data->tex->ce),
			free(data->tex->fl), free(data->tex), free(data), NULL);
	return (data);
}

t_data	*set_null_data(t_data *data)
{
	data->tex->no = NULL;
	data->tex->so = NULL;
	data->tex->we = NULL;
	data->tex->ea = NULL;
	data->tex->door = NULL;
	data->tex->fl->blue = 300;
	data->tex->ce->blue = 300;
	data->map = NULL;
	return (data);
}

int	mouse_hook(t_data *data)
{
	data->mx = 0;
	data->my = 0;
	mlx_mouse_get_pos(data->mlx, data->win, &data->mx, &data->my);
	if (data->mx > data->xo)
	{
		data->rr = 1;
		data->rl = 0;
	}
	if (data->mx < data->xo)
	{
		data->rl = 1;
		data->rr = 0;
	}
	if (data->mx == data->xo)
	{
		data->rl = 0;
		data->rr = 0;
	}
	return (0);
}

void	lauch_mlx(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img,
			&data->img->bits_per_pixel,
			&data->img->line_length, &data->img->endian);
	mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_get_pos(data->mlx, data->win, &data->xo, &data->yo);
	mlx_hook(data->win, 17, (1L << 17), &cross_kill, data);
	mlx_hook(data->win, 2, (1L << 0), &key_press, data);
	mlx_hook(data->win, 3, (1L << 1), &key_release, data);
	mlx_loop_hook(data->mlx, &handle_no_event, data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = 0;
	data = NULL;
	if (argc != 2)
		return (printf("Error\nNeed maps .cub\n"));
	while (argv[1][i])
		i++;
	if (i < 5)
		return (printf("Error\nNeed a map .cub\n"));
	i -= 4;
	if (ft_strncmp(&argv[1][i], ".cub", 4))
		return (printf("Error\nNeed a map .cub\n"));
	data = init_data(data);
	if (!data)
		return (1);
	data = set_null_data(data);
	data->mlx = mlx_init();
	if (parsing(data, argv[1]))
		return (1);
	rayinit(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	mlx_loop(data->mlx);
	return (0);
}
