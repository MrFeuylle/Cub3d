/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_placeholder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:53:22 by jlarue            #+#    #+#             */
/*   Updated: 2023/11/29 13:47:21 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rayinit_2(t_data	*data)
{
	data->rl = 0;
	data->rr = 0;
	data->mb = 0;
	data->mf = 0;
	data->ml = 0;
	data->mr = 0;
	data->opdo = 0;
	data->op = 0;
	data->minimap = 0;
}

void	rayinit(t_data	*data)
{
	data->ray->raydirx = 0;
	data->ray->raydiry = 0;
	data->ray->sidedistx = 0;
	data->ray->sidedisty = 0;
	data->ray->deltadistx = 0;
	data->ray->deltadisty = 0;
	data->ray->perpwalldist = 0;
	data->ray->camerax = 0;
	data->ray->lineheight = 0;
	data->ray->mapx = 0;
	data->ray->mapy = 0;
	data->ray->drawstart = 0;
	data->ray->drawend = 0;
	data->ray->side = 0;
	data->ray->stepx = 0;
	data->ray->stepy = 0;
	data->ray->hit = 0;
	rayinit_2(data);
	lauch_mlx(data);
	do_floor_cel(data);
	raycast(data);
}
