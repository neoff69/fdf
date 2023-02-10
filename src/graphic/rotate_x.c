/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:05:22 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/07 10:10:50 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

static void	fill_tab_rotate_x_r(float rotation[3][3])
{
	float	pi;

	pi = 3.14159;
	rotation[0][0] = 1;
	rotation[0][1] = 0;
	rotation[0][2] = 0;
	rotation[1][0] = 0;
	rotation[1][1] = cos(pi / 48);
	rotation[1][2] = -sin(pi / 48);
	rotation[2][0] = 0;
	rotation[2][1] = sin(pi / 48);
	rotation[2][2] = cos(pi / 48);
}

static void	fill_tab_rotate_x_f(float rotation[3][3])
{
	float	pi;

	pi = 3.14159;
	rotation[0][0] = 1;
	rotation[0][1] = 0;
	rotation[0][2] = 0;
	rotation[1][0] = 0;
	rotation[1][1] = cos(pi / 48);
	rotation[1][2] = sin(pi / 48);
	rotation[2][0] = 0;
	rotation[2][1] = -sin(pi / 48);
	rotation[2][2] = cos(pi / 48);
}

void	rotate_x(t_env *env, int x, int y)
{
	float	rotation[3][3];

	if (env->rotate == 'R')
		fill_tab_rotate_x_r(rotation);
	if (env->rotate == 'F')
		fill_tab_rotate_x_f(rotation);
	env->map[y][x].y -= 540;
	matmult3x3(&env->map[y][x].x, &env->map[y][x].y, \
				&env->map[y][x].z, rotation);
	env->map[y][x].y += 540;
}
