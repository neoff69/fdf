/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:50:12 by vgonnot           #+#    #+#             */
/*   Updated: 2023/01/10 09:44:58 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

static void	fill_tab_rotate_y_q(float rotation[3][3])
{
	float	pi;

	pi = 3.14159;
	rotation[0][0] = cos(pi / 48);
	rotation[0][1] = 0;
	rotation[0][2] = sin(pi / 48);
	rotation[1][0] = 0;
	rotation[1][1] = 1;
	rotation[1][2] = 0;
	rotation[2][0] = -sin(pi / 48);
	rotation[2][1] = 0;
	rotation[2][2] = cos(pi / 48);
}

static void	fill_tab_rotate_y_e(float rotation[3][3])
{
	float	pi;

	pi = 3.14159;
	rotation[0][0] = cos(pi / 48);
	rotation[0][1] = 0;
	rotation[0][2] = -sin(pi / 48);
	rotation[1][0] = 0;
	rotation[1][1] = 1;
	rotation[1][2] = 0;
	rotation[2][0] = sin(pi / 48);
	rotation[2][1] = 0;
	rotation[2][2] = cos(pi / 48);
}

void	rotate_y(t_env *env, int x, int y)
{
	float	rotation[3][3];

	if (env->rotate == 'Q')
		fill_tab_rotate_y_q(rotation);
	if (env->rotate == 'E')
		fill_tab_rotate_y_e(rotation);
	env->map[y][x].x -= 960;
	matmult3x3(&env->map[y][x].x, &env->map[y][x].y, \
				&env->map[y][x].z, rotation);
	env->map[y][x].x += 960;
}
