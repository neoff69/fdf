/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:37:03 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/07 10:07:29 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (env == NULL)
		return (-1);
	if (argc != 2)
	{
		free(env);
		return (-1);
	}
	parsing(env, argv[1]);
	setup_mlx(env);
	quit_function(0, env);
}
