/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 14:50:34 by mel-assa          #+#    #+#             */
/*   Updated: 2026/10/11 18:36:22 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_fractal(t_fractal *fractal)
{
	if (fractal->image)
		mlx_destroy_image(fractal->mlx, fractal->image);
	if (fractal->window)
		mlx_destroy_window(fractal->mlx, fractal->window);
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
}

int	close_window(t_fractal *fractal)
{
	destroy_fractal(fractal);
	exit(0);
	return (0);
}

int	handle_key(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		close_window(fractal);
	return (0);
}

int	handle_zoom(int button, int x, int y, t_fractal *fractal)
{
	t_complex	before;
	t_complex	after;

	if (button != 4 && button != 5)
		return (0);
	before = pixel_to_complex(fractal, x, y);
	if (button == 4)
		fractal->zoom *= 1.1;
	else
		fractal->zoom /= 1.1;
	after = pixel_to_complex(fractal, x, y);
	fractal->offset_real += before.real - after.real;
	fractal->offset_imaginary += before.imaginary - after.imaginary;
	render_fractal(fractal);
	return (0);
}
