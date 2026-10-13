/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:26:08 by mel-assa          #+#    #+#             */
/*   Updated: 2026/10/11 18:07:11 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pixel_to_complex(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	double		range_real;
	double		range_imaginary;

	range_real = (fractal->max_real - fractal->min_real)
		/ fractal->zoom;
	range_imaginary = (fractal->max_imaginary
			- fractal->min_imaginary) / fractal->zoom;
	c.real = fractal->min_real + fractal->offset_real
		+ (double)x * range_real / (WIDTH - 1);
	c.imaginary = fractal->max_imaginary + fractal->offset_imaginary
		- (double)y * range_imaginary / (HEIGHT - 1);
	return (c);
}

static int	get_iterations(t_complex z, t_complex c)
{
	double		temp;
	int			i;

	i = 0;
	while (i < MAX_ITER)
	{
		if (z.real * z.real + z.imaginary * z.imaginary > 4.0)
			break ;
		temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
		z.imaginary = 2.0 * z.real * z.imaginary + c.imaginary;
		z.real = temp;
		i++;
	}
	return (i);
}

int	mandelbrot_iterations(t_complex c)
{
	t_complex	z;

	z.real = 0.0;
	z.imaginary = 0.0;
	return (get_iterations(z, c));
}

int	julia_iterations(t_complex z, t_fractal *fractal)
{
	t_complex	c;

	c.real = fractal->julia_real;
	c.imaginary = fractal->julia_imaginary;
	return (get_iterations(z, c));
}
