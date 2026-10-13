/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:22:59 by mel-assa          #+#    #+#             */
/*   Updated: 2026/10/13 18:57:17 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	valid_arguments(int argc, char **argv)
{
	if (argc < 2 || argc > 4 || (ft_strncmp(argv[1], "mandelbrot", 11)
			&& ft_strncmp(argv[1], "julia", 6)))
		return (0);
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc != 2)
		return (0);
	if (ft_strncmp(argv[1], "julia", 6) == 0 && argc != 2 && argc != 4)
		return (0);
	if (argc == 4 && (!is_valid_double(argv[2]) || !is_valid_double(argv[3])))
		return (0);
	return (1);
}

static void	initialize_fractal(t_fractal *fractal, int argc, char **argv)
{
	fractal->name = argv[1];
	fractal->min_real = -2.0;
	fractal->max_real = 1.0;
	fractal->min_imaginary = -1.125;
	fractal->max_imaginary = 1.125;
	fractal->zoom = 1.0;
	fractal->julia_real = -0.7;
	fractal->julia_imaginary = 0.27015;
	if (argc == 4)
	{
		fractal->julia_real = ft_atod(argv[2]);
		fractal->julia_imaginary = ft_atod(argv[3]);
	}
}

static int	initialize_graphics(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		return (0);
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fractol");
	if (!fractal->window)
		return (0);
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->image)
		return (0);
	fractal->pixel_data = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);
	if (fractal->pixel_data)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!valid_arguments(argc, argv))
	{
		write(1, "Usage: ./fractol mandelbrot | julia [real imaginary]\n", 54);
		return (1);
	}
	initialize_fractal(&fractal, argc, argv);
	if (!initialize_graphics(&fractal))
	{
		destroy_fractal(&fractal);
		return (1);
	}
	render_fractal(&fractal);
	mlx_hook(fractal.window, 17, 0, close_window, &fractal);
	mlx_key_hook(fractal.window, handle_key, &fractal);
	mlx_mouse_hook(fractal.window, handle_zoom, &fractal);
	mlx_loop(fractal.mlx);
	destroy_fractal(&fractal);
	return (0);
}
