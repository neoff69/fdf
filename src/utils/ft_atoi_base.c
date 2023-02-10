/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:36:28 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/16 09:40:18 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fdf.h"

static void	set_array(int *tab)
{
	int	i;

	i = 0;
	while (i < 255)
	{
		tab[i] = 0;
		i++;
	}
}

static int	check_double_char(char *base, int *tab)
{
	int	i;

	i = 0;
	set_array(tab);
	while (base[i])
	{
		tab[(int)base[i]] += 1;
		i++;
	}
	i = 0;
	if (tab['+'] == 1 || tab['-'] == 1
		|| tab['\t'] == 1 || tab['\n'] == 1
		|| tab['\v'] == 1 || tab['\f'] == 1
		|| tab['\r'] == 1 || tab[' '] == 1)
		return (0);
	while (base[i])
	{
		if (tab[(int)base[i]] > 1)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	put_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

static int	ft_putnbr_base_u(char *str, char *base, int *tab, int i)
{
	int	result;
	int	base_length;
	int	k;
	int	convert;

	base_length = ft_strlen(base);
	result = 0;
	while (str[i])
	{
		convert = str[i];
		k = 0;
		if (tab[convert] != 1)
			return (result);
		while (str[i] != base[k])
			k++;
		result = (result * base_length + k);
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			tab[255];
	long int	result;
	int			test;

	i = 0;
	put_uppercase(str);
	test = check_double_char(base, tab);
	if (test == 0)
		return (0);
	result = ft_putnbr_base_u(str, base, tab, i);
	return (result);
}
