/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:19:18 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/08 07:30:24 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

void	pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	dst = env->addr + (y * env->len + x * (env->bit / 8));
	*(unsigned int *)dst = color;
}

int	click_to_quit(t_env *env)
{
	quit_function(0, env);
	return (-1);
}

void	hook(t_env *env)
{
	mlx_hook(env->mlx_win, 02, 1L << 0, keyhook, env);
	mlx_hook(env->mlx_win, 17, 1L << 0, click_to_quit, env);
}

void	setup_mlx(t_env *env)
{
	env->mlx = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx, 1920, 1080, "FdF");
	env->img = mlx_new_image(env->mlx, 1920, 1080);
	if (env->img == NULL)
		quit_function(1, env);
	env->addr = mlx_get_data_addr(env->img, &env->bit, &env->len, &env->endian);
	if (env->addr == NULL)
		quit_function(1, env);
	set_point(env);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img, 0, 0);
	hook(env);
	mlx_loop(env->mlx);
}
