/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:51:33 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/30 12:53:35 by agiguair         ###   ########.fr       */
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

/*############################################################################*/
/*-----------------------------------DOOR.C-----------------------------------*/
/*############################################################################*/
void		open_door(t_data *data);
void		close_door(t_data *data);
void		if_nine_to_two(t_data *data);
void		closingdoor(t_data *data);
void		openingdoor(t_data *data);
/*############################################################################*/
/*-------------------------------EVENT_BONUS.C--------------------------------*/
/*############################################################################*/
int			handle_no_event(t_data *data);
void		toogle_minimap(t_data *data);
int			key_press(int keysym, void *d);
int			key_release(int keysym, void *d);
int			cross_kill(t_data *data);
/*############################################################################*/
/*----------------------------------EVENT.C-----------------------------------*/
/*############################################################################*/
int			handle_no_event(t_data *data);
int			key_press(int keysym, void *d);
int			key_release(int keysym, void *d);
int			cross_kill(t_data *data);
/*############################################################################*/
/*--------------------------------EVENTMOVE.C---------------------------------*/
/*############################################################################*/
void		view_player(t_data *data);
void		move_playerf(t_data *data);
void		move_playerb(t_data *data);
bool		check_not_to_close(t_data *data);
void		move_playerlr(t_data *data);
/*############################################################################*/
/*--------------------------------FREE/BONUS.C--------------------------------*/
/*############################################################################*/
void		ffree(void *p);
void		mlx_free(t_data *data);
void		free_tex(t_data *data);
void		free_all(t_data *data);
/*############################################################################*/
/*-----------------------------MAIN_PLACEHOLDER.C-----------------------------*/
/*############################################################################*/
void		rayinit_2(t_data	*data);
void		rayinit(t_data	*data);
/*############################################################################*/
/*-----------------------------------MAIN.C-----------------------------------*/
/*############################################################################*/
t_data		*init_data(t_data *data);
t_data		*set_null_data(t_data *data);
int			mouse_hook(t_data *data);
void		lauch_mlx(t_data *data);
int			main(int argc, char **argv);
/*############################################################################*/
/*--------------------------------MAP_CHECK01.C-------------------------------*/
/*############################################################################*/
bool		check_single_player(char **map);
bool		check_surrounding_walls_line(char **map);
bool		check_surrounding_walls_col(char **map);
bool		map_error_controler(char **map, t_data *data);
/*############################################################################*/
/*----------------------------MAP_CHECK02/BONUS.C-----------------------------*/
/*############################################################################*/
bool		check_next_char_line(char **map, int i, int j);
bool		check_prev_char_line(char **map, int i, int j);
bool		check_next_char_col(char **map, int i, int j);
int			check_prevline(char **map, int i, int j);
bool		check_prev_char_col(char **map, int i, int j);
/*############################################################################*/
/*------------------------------MINIMAP_UTILS.C-------------------------------*/
/*############################################################################*/
int			map_size_scale(char **map);
/*############################################################################*/
/*---------------------------------MINIMAP.C----------------------------------*/
/*############################################################################*/
t_mini		*set_mini(t_data *data, double angle, t_mini *mini);
void		draw_ray_on_minimap(t_data *data, double angle, int color);
int			draw_square_outline(t_data *data, int cppw, int x, int y);
void		do_map(t_data *data, int x, int y);
void		clear_map(t_data *data);
/*############################################################################*/
/*-----------------------------MY_MLX_PIXEL_PUT.C-----------------------------*/
/*############################################################################*/
void		my_mlx_pixel_put(t_data *data, double x, double y, int color);
/*############################################################################*/
/*------------------------------PARSING/BONUS.C-------------------------------*/
/*############################################################################*/
char		*get_path(char *str);
t_texture	*do_img(t_data *data, char *path);
void		set_tex(t_data *data, t_texture *img, char *emp);
int			check_tex(t_data *data, char *str, char *emp);
bool		parsing(t_data *data, char *str);
/*############################################################################*/
/*-----------------------------PARSING_BONUS2.C-------------------------------*/
/*############################################################################*/
void		check_door(t_data *data, int i);
bool		check_all_bonus(t_data *data);
bool		check_file(t_data *data, int i);
/*############################################################################*/
/*------------------------------PARSING_UTILS.C-------------------------------*/
/*############################################################################*/
void		check_fc(t_data *data, char *str);
bool		check_rgb(t_rgb *rgb);
bool		check_map(char *str);
bool		check_all(t_data *data);
bool		ft_strcmp(char *str, char *str2);
/*############################################################################*/
/*-----------------------------PARSING_UTILS2.C-------------------------------*/
/*############################################################################*/
bool		error_double(t_double d);
t_double	set_zero_double(void);
void		do_wh_map(t_data *data);
bool		check_double(t_data *data);
char		**get_file(int fd, int nbl);
/*############################################################################*/
/*-------------------------------PLAYER_INIT.C--------------------------------*/
/*############################################################################*/
void		init_player_direction(char dir, t_player *player);
void		init_player_position(t_player *player, char **map);
/*############################################################################*/
/*-----------------------------RAYCASTING/BONUS.C-----------------------------*/
/*############################################################################*/
void		set_value_for_x(t_data *data, int x);
void		stepin(t_data *data);
void		set_value_for_x(t_data *data, int x);
void		whithit(t_data *data, int x);
void		raycast(t_data *data);
/*############################################################################*/
/*----------------------------RAYCASTING_BONUS2.C-----------------------------*/
/*############################################################################*/
void		check_hit(t_data *data);
/*############################################################################*/
/*-----------------------------RAYCASTING_UTILS.C-----------------------------*/
/*############################################################################*/
t_texture	*get_texture(t_data *data);
void		set_ray_dl(t_data *data, t_texture *texture);
void		draw_line(t_data *data, int x, int y1, int y2);
/*############################################################################*/
/*----------------------------------RENDER.C----------------------------------*/
/*############################################################################*/
int			rgb_to_int(t_rgb *rgb);
void		do_floor_cel(t_data *data);
int			do_square(t_data *data, int cppw, int x, int y);
int			do_square_door(t_data *data, int cppw, int x, int y);
void		set_on_map_player(t_data *data, int cppw);
#endif
