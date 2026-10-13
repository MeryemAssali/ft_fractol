/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:55:57 by mel-assa          #+#    #+#             */
/*   Updated: 2026/10/13 18:40:36 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iterations)
{
	int	r;
	int	g;
	int	b;

	if (iterations == MAX_ITER)
		return (0x000000);
	r = (iterations * 5) % 256;
	g = (iterations * 10) % 256;
	b = (iterations * 15) % 256;
	return ((r << 16) | (g << 8) | b);
}

static double	get_decimal(const char *str, int i)
{
	double	decimal_place;
	double	decimal;

	decimal_place = 1.0;
	decimal = 0.0;
	while (ft_isdigit(str[i]))
	{
		decimal_place *= 10.0;
		decimal += (str[i] - '0') / decimal_place;
		i++;
	}
	return (decimal);
}

double	ft_atod(const char *str)
{
	double	number;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	number = 0.0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		number = number * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		number += get_decimal(str, i + 1);
	return (number * sign);
}

int	is_valid_double(char *str)
{
	int	i;
	int	digits;

	i = 0;
	digits = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		digits++;
		i++;
	}
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		digits++;
		i++;
	}
	if (digits > 0 && str[i] == '\0')
		return (1);
	return (0);
}
