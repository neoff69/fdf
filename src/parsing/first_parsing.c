/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:43:57 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/07 08:49:44 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

int	open_file(char *argv, t_env *env)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		quit_function(1, env);
	return (fd);
}

static int	get_number_line(t_env *env, char *str)
{
	char	**split_str;
	int		x;
	int		temp_z;

	split_str = ft_split(str, ' ');
	x = 0;
	while (split_str[x])
	{
		temp_z = ft_atoi_custom(split_str[x], env, -1, -1);
		if (env->max_z < temp_z)
			env->max_z = temp_z;
		if (env->min_z > temp_z)
			env->min_z = temp_z;
		x++;
	}
	free_double_malloc(split_str);
	return (x);
}

void	first_parsing(t_env *env, char *argv)
{
	int		fd;
	char	*line;
	int		temp;

	fd = open_file(argv, env);
	line = get_next_line(fd);
	if (line == NULL)
		quit_function(1, env);
	while (line != NULL)
	{
		temp = get_number_line(env, line);
		if (temp > env->max_x)
			env->max_x = temp;
		env->max_y += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
