/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_placeholder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:53:22 by jlarue            #+#    #+#             */
/*   Updated: 2023/11/22 16:19:31 by jlarue           ###   ########.fr       */
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
	data->minimap = 0;
}
