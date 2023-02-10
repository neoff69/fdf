/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:09:04 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/07 09:38:18 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

void	struct_initialize(t_env *env)
{
	env->max_y = 0;
	env->max_x = 0;
	env->max_y_pos = 0;
	env->max_x_pos = 0;
	env->max_z = NO_PIXEL;
	env->min_z = INT_MAX;
	env->map = NULL;
	env->zoom = 1;
	env->mv_ud = 0;
	env->mv_lr = 0;
	env->left_pos_y = -1;
	env->left_pos_x = -1;
	env->up_pos_y = -1;
	env->up_pos_x = -1;
	env->no_color = 1;
	env->green = 0;
	env->rotate = 0;
	env->draw_line = 1;
	env->img = NULL;
	env->mlx_win = NULL;
	env->mlx = NULL;
}

int	point_in_screen(int x, int y)
{
	if (0 < x && x < 1920 && 0 < y && y < 1080)
		return (1);
	return (0);
}
