/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 15:44:30 by mel-assa          #+#    #+#             */
/*   Updated: 2026/10/11 18:12:17 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_fractal *fractal)
{
	int			x;
	int			y;
	int			color;
	t_complex	point;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			point = pixel_to_complex(fractal, x, y);
			if (ft_strncmp(fractal->name, "mandelbrot", 11) == 0)
				color = mandelbrot_iterations(point);
			else
				color = julia_iterations(point, fractal);
			put_pixel(fractal, x, y, get_color(color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
}

void	put_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	pixel_index;

	pixel_index = y * fractal->line_length
		+ x * (fractal->bits_per_pixel / 8);
	*(unsigned int *)(fractal->pixel_data + pixel_index) = color;
}
