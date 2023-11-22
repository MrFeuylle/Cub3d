/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:24:26 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/22 15:57:32 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*get_path(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '	') && str[i])
		i++;
	if (((str[i] == 'N' || str[i] == 'S') && str[i + 1] == 'O')
		|| (str[i] == 'W' && str[i + 1] == 'E')
		|| (str[i] == 'E' && str[i + 1] == 'A')
		|| (str[i] == 'D' && str[i + 1] == 'O'))
	{
		i += 2;
		while ((str[i] == ' ' || str[i] == '	') && str[i])
			i++;
		return (&str[i]);
	}
	return (NULL);
}

t_texture	*do_img(t_data *data, char *path)
{
	t_texture	*tex;

	tex = malloc(sizeof(t_texture));
	tex->img = mlx_xpm_file_to_image(data->mlx,
			path, &tex->width, &tex->height);
	if (!tex->img)
		return (NULL);
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bits_per_pixel, &tex->line_length, &tex->endian);
	return (tex);
}

int	check_tex(t_data *data, char *str, char *emp)
{
	t_texture	*img;
	char		*path;

	path = get_path(str);
	if (!path)
		return (printf("Error\nCan't find the path at %s", str));
	path = ft_strtrim(path, "\n");
	img = do_img(data, path);
	free(path);
	if (!img)
		return (printf("Error\nCan't open the xpm at line %s", str));
	if (emp[0] == 'n')
		data->tex->no = img;
	if (emp[0] == 's')
		data->tex->so = img;
	if (emp[0] == 'w')
		data->tex->we = img;
	if (emp[0] == 'e')
		data->tex->ea = img;
	if (emp[0] == 'd')
		data->tex->door = img;
	return (0);
}

bool	check_file(t_data *data)
{
	int	i;

	i = -1;
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
		else if (ft_strcmp(data->file[i], "DO "))
			check_tex(data, data->file[i], "do");
		else if (ft_strcmp(data->file[i], "F "))
			check_fc(data, data->file[i]);
		else if (ft_strcmp(data->file[i], "C "))
			check_fc(data, data->file[i]);
		else if (check_map(data->file[i]))
		{
			if (!map_error_controler(&data->file[i], data))
				data->map = &data->file[i];
			break ;
		}
	}
	return (check_all(data));
}

bool	parsing(t_data *data, char *str)
{
	int		fd;
	int		nbl;
	char	*str2;

	nbl = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (printf("Error\n"), perror(str), TRUE);
	str2 = get_next_line(fd);
	while (str2)
	{
		free(str2);
		nbl++;
		str2 = get_next_line(fd);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		printf("ici\n");
		return (printf("Error\n"), perror(str), TRUE);
	}
	data->file = get_file(fd, nbl);
	if (check_double(data))
		return (TRUE);
	if (check_file(data))
		return (TRUE);
	return (FALSE);
}
