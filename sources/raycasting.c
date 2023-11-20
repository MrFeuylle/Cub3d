/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:43:30 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/20 18:00:33 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_line(t_data *data, int x, int y1, int y2, t_texture *texture)
{
    int y;
	t_rgb rgb;

    y = y1;
    while (y <= y2)
    {
        int tex_y = (y - y1) * texture->height / (y2 - y1 + 1);
        int tex_offset = tex_y * texture->line_length + x * (texture->bits_per_pixel / 8);
		rgb.red = (unsigned char)texture->addr[tex_offset + 2];
        rgb.green = (unsigned char)texture->addr[tex_offset + 1];
        rgb.blue = (unsigned char)texture->addr[tex_offset];
        my_mlx_pixel_put(data, x, y, rgb_to_int(&rgb));
		y++;
    }
}

void raycast(t_data *data)
{
    int x;

    x = 0;
    while (x < WIDTH)
    {
        data->ray->camerax = 2 * x / (double)WIDTH - 1;
        data->ray->raydiry = data->player->dy + data->player->plane_y * data->ray->camerax;
        data->ray->raydirx = data->player->dx + data->player->plane_x * data->ray->camerax;

        data->ray->deltadistx = fabs(1 / data->ray->raydirx);
        data->ray->deltadisty = fabs(1 / data->ray->raydiry);

        data->ray->hit = 0;

        data->ray->mapx = (int)data->player->x;
        data->ray->mapy = (int)data->player->y;
        if (data->ray->raydirx < 0)
        {
            data->ray->stepx = -1;
            data->ray->sidedistx = (data->player->x - data->ray->mapx) * data->ray->deltadistx;
        }
        else
        {
            data->ray->stepx = 1;
            data->ray->sidedistx = (data->ray->mapx + 1.0 - data->player->x) * data->ray->deltadistx;
        }

        if (data->ray->raydiry < 0)
        {
            data->ray->stepy = -1;
            data->ray->sidedisty = (data->player->y - data->ray->mapy) * data->ray->deltadisty;
        }
        else
        {
            data->ray->stepy = 1;
            data->ray->sidedisty = (data->ray->mapy + 1.0 - data->player->y) * data->ray->deltadisty;
        }

        while (!data->ray->hit)
        {
            if (data->ray->sidedistx < data->ray->sidedisty)
            {
                data->ray->sidedistx += data->ray->deltadistx;
                data->ray->mapx += data->ray->stepx;
                data->ray->side = 0;
            }
            else
            {
                data->ray->sidedisty += data->ray->deltadisty;
                data->ray->mapy += data->ray->stepy;
                data->ray->side = 1;
            }

            // Vérifier la collision avec les murs
            if (data->map[data->ray->mapy][data->ray->mapx] == '1')
                data->ray->hit = 1;

            if (data->ray->side == 0)
                data->ray->perpwalldist = (data->ray->mapx - data->player->x + (1 - data->ray->stepx) / 2) / data->ray->raydirx;
            else
                data->ray->perpwalldist = (data->ray->mapy - data->player->y + (1 - data->ray->stepy) / 2) / data->ray->raydiry;

            // Calculer la hauteur du mur
            int line_height = (int)(HEIGHT / data->ray->perpwalldist);

            // Calculer la position de début et de fin pour dessiner la ligne
            int draw_start = -line_height / 2 + HEIGHT / 2;
            if (draw_start < 0)
                draw_start = 0;
            int draw_end = line_height / 2 + HEIGHT / 2;
            if (draw_end >= HEIGHT)
                draw_end = HEIGHT - 1;

            // Dessiner la ligne
			if (data->map[data->ray->mapy][data->ray->mapx] == '1')
			{
            	draw_line(data, x, draw_start, draw_end, data->tex->no);
			}
        }

        x++;
    }
}
