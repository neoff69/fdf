/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:56:14 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/06 12:49:59 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

void	matmult3x3(double *x, double *y, double *z, float mat[3][3])
{
	int		i;
	int		j;
	float	matxyz[3];

	matxyz[0] = *x;
	matxyz[1] = *y;
	matxyz[2] = *z;
	i = 0;
	*x = 0;
	*y = 0;
	*z = 0;
	while (i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (i == 0)
				*x += mat[i][j] * matxyz[j];
			else if (i == 1)
				*y += mat[i][j] * matxyz[j];
			else
				*z += mat[i][j] * matxyz[j];
		}	
		i++;
	}
}

void	check_which_rotate(t_env *env, int x, int y)
{
	if (env->rotate == 'R' || env->rotate == 'F')
		rotate_x(env, x, y);
	if (env->rotate == 'Q' || env->rotate == 'E')
		rotate_y(env, x, y);
	else if (env->rotate == '1' || env->rotate == '2')
		rotate_z(env, x, y);
}

void	rotate_fun(t_env *env, int keycode)
{
	if (keycode == KEY_R)
		env->rotate = 'R';
	else if (keycode == KEY_F)
		env->rotate = 'F';
	else if (keycode == KEY_Q)
		env->rotate = 'Q';
	else if (keycode == KEY_E)
		env->rotate = 'E';
	else if (keycode == KEY_1)
		env->rotate = '1';
	else if (keycode == KEY_2)
		env->rotate = '2';
	set_image_win(env);
}
