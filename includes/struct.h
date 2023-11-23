/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:51:36 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/23 11:17:24 by agiguair         ###   ########.fr       */
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

typedef struct s_mini
{
	int	cppw;
	int	cpph;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_mini;

typedef struct s_texture {
	void	*img;
	int		**tab;
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
	t_texture	*door;
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
	double	fov;
	double	rayangle;
	double	texpos;
	double	step;
	double	wallx;
	int		tex_offset;
	int		texx;
	int		texy;
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

typedef struct s_line
{
	int	x;
	int	y;
	int	y0;
	int	y1;
	int	tex_x;
	int	tex_y;
}	t_line;

typedef struct s_data
{
	void		*mlx;
	int			rl;
	int			rr;
	int			mb;
	int			opdo;
	int			mf;
	int			ml;
	int			mr;
	int			yo;
	int			xo;
	int			mx;
	int			my;
	int			minimap;
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
