/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:51:33 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/16 21:15:13 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include "struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

/*--------map_check01.c--------*/
bool	error_controler(char **map);
int		check_surrounding_walls_col(char **map);
int		check_surrounding_walls_line(char **map);
int		check_single_player(char **map);
/*--------map_check02.c--------*/
int		check_next_char_line(char **map, int i, int j);
int		check_prev_char_line(char **map, int i, int j);
int		check_next_char_col(char **map, int i, int j);
int		check_prev_char_col(char **map, int i, int j);
#endif
