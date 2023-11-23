/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:46:06 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/23 11:46:17 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	char	*dst;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	dst = data->img->addr + ((int)round(y) * data->img->line_length
			+ (int)round(x) * (data->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
