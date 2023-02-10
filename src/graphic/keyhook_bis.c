/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:07:06 by vgonnot           #+#    #+#             */
/*   Updated: 2023/01/08 08:10:36 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

void	zoom_fun(t_env *env, int keycode)
{
	if (keycode == KEY_PLUS || keycode == KEY_PLUS_2)
		env->zoom *= 1.025;
	else
		env->zoom *= 0.975;
	set_image_win(env);
}

void	remove_line_fun(t_env *env, int keycode)
{
	if (keycode == KEY_V)
		env->draw_line = 1;
	else
		env->draw_line = 0;
	set_image_win(env);
}
