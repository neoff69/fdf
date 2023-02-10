/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:58:49 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/07 08:50:18 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

static void	fill_tab_rotate_z_1(float rotation[3][3])
{
	float	pi;

	pi = 3.14159;
	rotation[0][0] = cos(pi / 48);
	rotation[0][1] = -sin(pi / 48);
	rotation[0][2] = 0;
	rotation[1][0] = sin(pi / 48);
	rotation[1][1] = cos(pi / 48);
	rotation[1][2] = 0;
	rotation[2][0] = 0;
	rotation[2][1] = 0;
	rotation[2][2] = 1;
}

static void	fill_tab_rotate_z_2(float rotation[3][3])
{
	float	pi;

	pi = 3.14159;
	rotation[0][0] = cos(pi / 48);
	rotation[0][1] = sin(pi / 48);
	rotation[0][2] = 0;
	rotation[1][0] = -sin(pi / 48);
	rotation[1][1] = cos(pi / 48);
	rotation[1][2] = 0;
	rotation[2][0] = 0;
	rotation[2][1] = 0;
	rotation[2][2] = 1;
}

void	rotate_z(t_env *env, int x, int y)
{
	float	rotation[3][3];

	if (env->rotate == '1')
		fill_tab_rotate_z_1(rotation);
	if (env->rotate == '2')
		fill_tab_rotate_z_2(rotation);
	env->map[y][x].x -= 960;
	env->map[y][x].y -= 540;
	matmult3x3(&env->map[y][x].x, &env->map[y][x].y, \
				&env->map[y][x].z, rotation);
	env->map[y][x].x += 960;
	env->map[y][x].y += 540;
}
