/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:59:56 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/07 10:28:19 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

static void	moving_fun(t_env *env, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		env->mv_ud += 25;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		env->mv_ud -= 25;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		env->mv_lr += 25;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		env->mv_lr -= 25;
	set_image_win(env);
}

static void	color_fun(t_env *env, int keycode)
{
	if (keycode == KEY_X)
	{
		env->no_color = 0;
		env->green = 0x00FF00;
	}
	else if (keycode == KEY_C)
	{
		env->no_color = 1;
		env->green = 0;
	}
	set_image_win(env);
}

static int	check_if_moving(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		return (1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		return (1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		return (1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		return (1);
	return (0);
}

static int	check_if_rotate(int keycode)
{
	if (keycode == KEY_R || keycode == KEY_F)
		return (1);
	if (keycode == KEY_Q || keycode == KEY_E)
		return (1);
	if (keycode == KEY_1 || keycode == KEY_2)
		return (1);
	return (0);
}

int	keyhook(int keycode, t_env *env)
{
	if (keycode == KEY_ESCAPE)
		quit_function(0, env);
	else if (keycode == KEY_PLUS || keycode == KEY_PLUS_2
		|| keycode == KEY_MINUS || keycode == KEY_MINUS_2)
		zoom_fun(env, keycode);
	else if (check_if_moving(keycode))
		moving_fun(env, keycode);
	else if (check_if_rotate(keycode))
		rotate_fun(env, keycode);
	else if (keycode == KEY_X || keycode == KEY_C)
		color_fun(env, keycode);
	else if (keycode == KEY_V || keycode == KEY_B)
		remove_line_fun(env, keycode);
	return (0);
}
