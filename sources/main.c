/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:06:25 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/17 06:05:34 by agiguair         ###   ########.fr       */
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
	return (data);
}

t_data	*set_null_data(t_data *data)
{
	data->tex->no = NULL;
	data->tex->so = NULL;
	data->tex->we = NULL;
	data->tex->ea = NULL;
	data->tex->fl->blue = 300;
	data->tex->ce->blue = 300;
	data->map = NULL;
	return (data);
}

void	lauch_mlx(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	mlx_loop_hook(data->mlx, &handle_no_event, data);
	mlx_key_hook(data->win, &handle_input, data);
	mlx_hook(data->win, 17, (1L << 17), &cross_kill, data);
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
	lauch_mlx(data);
	mlx_loop(data->mlx);
	return (0);
}
