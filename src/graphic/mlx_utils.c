/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:04:17 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/07 10:55:22 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

void	set_param_default_value(t_env *env)
{
	env->zoom = 1;
	env->mv_ud = 0;
	env->mv_lr = 0;
	env->rotate = 0;
}

void	set_center(t_env *env, int y, int x)
{
	if (env->map[y][x].check == 0)
	{
		env->map[y][x].check = 1;
		env->map[y][x].y = (env->map[y][x].y / env->max_y_pos + 1) * 400;
		env->map[y][x].x = (env->map[y][x].x / env->max_x_pos + 1) * 960;
	}
}

void	check_movement(t_env *env, int y, int x)
{
	if (env->zoom != 1.00 || env->mv_ud != 0.0 || env->mv_lr != 0.0)
	{
		env->map[y][x].x = env->map[y][x].x * env->zoom + env->mv_lr;
		env->map[y][x].y = env->map[y][x].y * env->zoom + env->mv_ud;
	}
}

void	set_point(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->max_y)
	{
		x = 0;
		while (x < env->max_x && env->map[y][x].y != NO_PIXEL)
		{
			set_center(env, y, x);
			check_movement(env, y, x);
			if (env->rotate != 0)
				check_which_rotate(env, x, y);
			if (env->draw_line)
				draw_line(env, env->map[y][x].color * env->no_color \
						+ env->green, y, x);
			else if (env->draw_line == 0 && \
			point_in_screen(env->map[y][x].x, env->map[y][x].y))
				pixel_put(env, env->map[y][x].x, env->map[y][x].y, \
				env->map[y][x].color * env->no_color + env->green);
			x++;
		}
		y ++;
	}
	set_param_default_value(env);
}

void	set_image_win(t_env *env)
{
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, 1920, 1080);
	if (env->img == NULL)
		quit_function(1, env);
	env->addr = mlx_get_data_addr(env->img, &env->bit, &env->len, &env->endian);
	if (env->addr == NULL)
		quit_function(1, env);
	set_point(env);
	mlx_clear_window(env->mlx, env->mlx_win);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img, 0, 0);
}
