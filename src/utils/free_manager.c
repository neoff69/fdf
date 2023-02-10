/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:26:30 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/07 08:19:09 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

void	free_simple_malloc(char *array)
{
	free(array);
}

void	free_double_malloc(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	free_map(t_env *env)
{
	int	y;

	y = 0;
	while (y < env->max_y)
	{
		free(env->map[y]);
		y++;
	}
	free(env->map);
}

int	quit_function(int error, t_env *env)
{
	if (env->img != NULL)
		mlx_destroy_image(env->mlx, env->img);
	if (env->mlx_win != NULL)
		mlx_destroy_window(env->mlx, env->mlx_win);
	if (env->mlx != NULL)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	if (env != NULL)
	{
		if (env->map != NULL)
			free_map(env);
		free(env);
	}
	if (error == 1)
	{
		ft_printf("Error : %s\n", strerror(errno));
		exit(-1);
	}
	else if (error == 2)
		exit(-1);
	exit (0);
}
