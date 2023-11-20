/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:51:36 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/20 16:08:31 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_double
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	fl;
	int	ce;
}	t_double;


typedef struct s_texture {
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_tex
{
	t_texture	*no;
	t_texture	*so;
	t_texture	*we;
	t_texture	*ea;
	int			width;
	int			height;
	t_rgb		*fl;
	t_rgb		*ce;
}	t_tex;


typedef struct s_player
{
	double		x;
	double		y;
	double		dx;
	double		dy;
	double		plane_x;
	double		plane_y;
}	t_player;

typedef struct s_ray
{
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	camerax;
	int		lineheight;
	int		mapx;
	int		mapy;
	int		drawstart;
	int		drawend;
	int		side;
	int		stepx;
	int		stepy;
	int		hit;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;


typedef	struct  s_line
{
	int  x; //the x coordinate of line relative to screen
	int  y; //the current pixel index of the line (along y axis)
	int  y0; //y start index of drawing texture
	int  y1; //y end index of drawing texture
	int  tex_x; //x coordinate of texture to draw
	int  tex_y; //y coordinate of texture to draw
} t_line;

typedef struct s_data
{
	void		*mlx;
	t_img		*img;
	t_tex		*tex;
	t_player	*player;
	char		**map;
	void		*win;
	t_ray		*ray;
	t_line		*line;
	int			w_map;
	int			h_map;
	int			movespeed;
	char		**file;
}	t_data;


#endif
