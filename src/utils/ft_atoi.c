/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:35:38 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/07 08:24:27 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

static int	check_sign(const char *sign, int *i)
{
	while ((sign[*i] >= 9 && sign[*i] <= 13) || sign[*i] == 32)
	{
		*i += 1;
	}
	if (sign[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	if (sign[*i] == '+')
		*i += 1;
	return (1);
}

void	get_color(t_env *env, char *str, int index, int j)
{
	if (str[0] == ',')
	{	
		env->map[index][j].color = ft_atoi_base(&str[3], "0123456789ABCDEF");
	}
	else
		env->map[index][j].color = 0xFFFFFF;
}

int	ft_atoi_custom(char *str, t_env *env, int index, int j)
{
	long long int			result;
	int						negative;
	int						i;

	i = 0;
	result = 0;
	negative = check_sign(&str[i], &i);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result += (str[i] - '0');
		result *= 10;
		i++;
	}
	if (index >= 0)
		get_color(env, &str[i], index, j);
	if (i == 0 || (!(str[i - 1] >= '0' && str[i - 1] <= '9')
			&& str[i - 1] != '\n' && str[i] != ','))
	{
		ft_printf("Map error char '%c' not allowed. \n", str[i - 1]);
		quit_function(2, env);
	}
	return (result / 10 * negative);
}
