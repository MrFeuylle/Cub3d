/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:51:33 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/23 11:45:28 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include "struct.h"
# define TRUE 1
# define FALSE 0
# define WIDTH 1200
# define HEIGHT 900
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
bool	map_error_controler(char **map, t_data *data);
bool	check_surrounding_walls_col(char **map);
bool	check_surrounding_walls_line(char **map);
bool	check_single_player(char **map);
/*--------map_check02.c--------*/
bool	check_next_char_line(char **map, int i, int j);
bool	check_prev_char_line(char **map, int i, int j);
bool	check_next_char_col(char **map, int i, int j);
bool	check_prev_char_col(char **map, int i, int j);
/*--------parsing_utils.c------*/
void	check_fc(t_data *data, char *str);
bool	check_rgb(t_rgb *rgb);
bool	check_map(char *str);
bool	check_all(t_data *data);
bool	ft_strcmp(char *str, char *str2);
/*----------parsing.c--------*/
char	**get_file(int fd, int nbl);
char	*get_path(char *str);
int		check_tex(t_data *data, char *str, char *emp);
bool	check_file(t_data *data, int i);
bool	parsing(t_data *data, char *str);
/*----------parsing_utils2.c--------*/
bool	error_double(t_double d);
bool	check_double(t_data *data);
/*-----------event.c---------------*/
int		handle_no_event(t_data *data);
int		handle_input(int keysym, t_data *data);
int		cross_kill(t_data *data);
/*--------------free.c-------------*/
void	free_all(t_data *data);
void	init_player_position(t_player *player, char **map);
void	raycasting(t_data *data);
void	do_floor_cel(t_data *data);
int		do_square(t_data *data, int cppw, int x, int y);
int		do_square_door(t_data *data, int cppw, int x, int y);
void	do_wh_map(t_data *data);
void	clear_map(t_data *data);
void	my_mlx_pixel_put(t_data *data, double x, double y, int color);
void	raycast(t_data *data);
int		rgb_to_int(t_rgb *rgb);
int		key_press(int keysym, void *data);
int		key_release(int keysym, void *data);
void	draw_line(t_data *data, int x, int y1, int y2);
void	draw_ray_on_minimap(t_data *data, double angle, int color);
bool	check_double(t_data *data);
char	**get_file(int fd, int nbl);
void	move_playerf(t_data *data);
void	move_playerb(t_data *data);
void	move_playerlr(t_data *data);
void	view_player(t_data *data);
void	clear_map(t_data *data);
void	do_map(t_data *data, int x, int y);
void	set_on_map_player(t_data *data, int cpph);
int		map_size_scale(char **map);
void	rayinit(t_data	*data);
void	rayinit_2(t_data	*data);
void	lauch_mlx(t_data *data);
int		mouse_hook(t_data *data);
void	open_door(t_data *data);
void	close_door(t_data *data);
void	toogle_minimap(t_data *data);
#endif
