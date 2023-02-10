/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:21:29 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/06 11:15:59 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

static float	get_upper_point(float *x1, int y, int x, t_env *env)
{
	int	y1;

	*x1 = NO_POINT;
	y1 = NO_POINT;
	if (y > 0)
	{	
		y1 = env->map[y - 1][x].y;
		*x1 = env->map[y - 1][x].x;
	}
	return (y1);
}

static float	get_left_point(float *x1, int y, int x, t_env *env)
{
	int	y1;

	*x1 = NO_POINT;
	y1 = NO_POINT;
	if (x > 0)
	{	
		y1 = env->map[y][x - 1].y;
		*x1 = env->map[y][x - 1].x;
	}
	return (y1);
}

static int	check_if_draw(t_env *env, int y2, int x2)
{
	if (env->y1 == NO_POINT && env->x1 == NO_POINT)
		return (0);
	if (((env->y1 < 0 && y2 < 0)) || (env->y1 > 1080 && y2 > 1080))
		return (0);
	if ((env->x1 < 0 && x2 < 0) || (env->x1 > 1920 && x2 > 1920))
		return (0);
	return (1);
}

static void	set_line(t_env *env, int y, int x, float (*function) \
						(float *, int, int, t_env *))
{
	float	xincr;
	float	yincr;
	int		i;

	i = -1;
	env->y1 = (*function)(&env->x1, y, x, env);
	env->dy = env->map[y][x].y - env->y1;
	env->dx = env->map[y][x].x - env->x1;
	if (fabs(env->dx) > fabs(env->dy))
		env->step = fabs(env->dx);
	else
		env->step = fabs(env->dy);
	xincr = env->dx / env->step;
	yincr = env->dy / env->step;
	if (check_if_draw(env, env->map[y][x].y, env->map[y][x].x))
	{
		while (++i < env->step)
		{
			if (point_in_screen(env->x1, env->y1))
				pixel_put(env, (int)env->x1, \
						(int)env->y1, env->actual_color);
			env->x1 += xincr;
			env->y1 += yincr;
		}
	}
}

void	draw_line(t_env *env, int color, int y, int x)
{
	env->actual_color = color;
	set_line(env, y, x, &get_left_point);
	set_line(env, y, x, &get_upper_point);
}
