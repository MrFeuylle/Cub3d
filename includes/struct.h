/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:51:36 by agiguair          #+#    #+#             */
/*   Updated: 2023/11/17 02:26:20 by agiguair         ###   ########.fr       */
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


typedef struct s_tex
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	int		width;
	int		height;
	t_rgb	*fl;
	t_rgb	*ce;
}	t_tex;


typedef struct s_data
{
	void	*mlx;
	void	*img;
	t_tex	*tex;
	char	**map;
	void	*win;
	char	**file;
}	t_data;

#endif
