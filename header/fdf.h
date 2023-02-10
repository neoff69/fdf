/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:07:38 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/07 10:07:20 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/header/libft.h"
# include "../minilibx-linux/mlx.h"
# include "keycode.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <errno.h>
# include <limits.h>
# include <math.h>

typedef struct t_map
{
	double		x;
	double		y;
	double		z;
	int			check;
	int			color;
}	t_map;

typedef struct t_env
{
	int		max_y;
	int		max_x;
	int		max_y_pos;
	int		max_x_pos;
	int		max_z;
	int		min_z;
	float	q;

	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bit;
	int		len;
	int		endian;
	double	zoom;
	char	rotate;
	int		mv_ud;
	int		mv_lr;
	int		no_color;
	int		green;
	int		actual_color;
	int		draw_line;

	int		left_pos_x;
	int		left_pos_y;
	int		up_pos_x;
	int		up_pos_y;
	float	y1;
	float	x1;
	float	dy;
	float	dx;
	int		step;
	double	perspective_mat[4][4];
	double	isometric_mat[4][4];
	t_map	**map;
}	t_env;

/*utils*/
int		quit_function(int error, t_env *env);
int		open_file(char *argv, t_env *env);
void	struct_initialize(t_env *env);
int		ft_atoi_custom(char *str, t_env *env, int index, int j);
void	set_image_win(t_env *env);
int		point_in_screen(int x, int y);
int		ft_atoi_base(char *str, char *base);

/*malloc utils*/
void	free_simple_malloc(char *array);
void	free_double_malloc(char **array);

/*parsing*/
void	parsing(t_env *env, char *argv);
void	first_parsing(t_env *env, char *argv);

/*graphic*/
void	pixel_put(t_env *env, int x, int y, int color);
void	setup_mlx(t_env *env);
void	set_point(t_env *env);
int		keyhook(int keycode, t_env *env);
void	draw_line(t_env *env, int color, int y, int x);
void	pixel_put(t_env *env, int x, int y, int color);
void	zoom_fun(t_env *env, int keycode);
void	remove_line_fun(t_env *env, int keycode);
void	rotate_fun(t_env *env, int keycode);
void	check_which_rotate(t_env *env, int x, int y);
void	rotate_x(t_env *env, int x, int y);
void	rotate_y(t_env *env, int x, int y);
void	rotate_z(t_env *env, int x, int y);
void	matmult3x3(double *x, double *y, double *z, float mat[3][3]);

#endif