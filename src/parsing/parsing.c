/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:19:27 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/07 09:38:48 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

static void	fill_if_nothing(t_env *env, int y, int x)
{
	env->map[y][x].x = NO_PIXEL;
	env->map[y][x].y = NO_PIXEL;
	env->map[y][x].z = NO_PIXEL;
	env->map[y][x].color = 0;
	env->map[y][x].check = 0;
}

static void	fill_if_something(t_env *env, int y, int x, char *str)
{
	env->map[y][x].check = 0;
	env->map[y][x].z = (double)ft_atoi_custom(str, env, y, x);
	env->map[y][x].x = (x - y) / cos(1 * M_PI_4);
	env->map[y][x].y = ((x + y) * sin(1 * M_PI_4)) - env->map[y][x].z / sqrt(3);
	if (env->map[y][x].z != 0)
		env->map[y][x].y = env->map[y][x].y - env->map[y][x].z;
	if (env->map[y][x].y > env->max_y_pos)
		env->max_y_pos = env->map[y][x].y;
	if (env->map[y][x].x > env->max_x_pos)
		env->max_x_pos = env->map[y][x].x;
}

static void	fill_struct(char *str, t_env *env, int y)
{
	char	**str_split;
	int		x;

	x = 0;
	env->map[y] = malloc(sizeof (t_map) * env->max_x);
	if (env->map[y] == NULL)
		quit_function(1, env);
	str_split = ft_split(str, ' ');
	while (str_split[x])
	{	
		if (str_split[x][0] == '\n')
			fill_if_nothing(env, y, x);
		else
			fill_if_something(env, y, x, str_split[x]);
		x++;
	}
	while (x < env->max_x)
	{
		fill_if_nothing(env, y, x);
		x++;
	}
	free_double_malloc(str_split);
}

void	parsing(t_env *env, char *argv)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	struct_initialize(env);
	first_parsing(env, argv);
	fd = open_file(argv, env);
	env->map = malloc(sizeof (t_map *) * env->max_y);
	if (env->map == NULL)
		quit_function(1, env);
	str = get_next_line(fd);
	while (str != NULL)
	{
		fill_struct(str, env, i);
		i++;
		free(str);
		str = get_next_line(fd);
	}
}
