/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:12:06 by mel-assa          #+#    #+#             */
/*   Updated: 2026/10/11 18:30:48 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_fractal
{
	void		*mlx;
	void		*window;
	void		*image;
	char		*pixel_data;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		zoom;
	double		offset_real;
	double		offset_imaginary;
	double		julia_real;
	double		julia_imaginary;
	double		min_real;
	double		max_real;
	double		min_imaginary;
	double		max_imaginary;
	char		*name;
}	t_fractal;

int				close_window(t_fractal *fractal);
int				handle_key(int keycode, t_fractal *fractal);
void			put_pixel(t_fractal *fractal, int x, int y, int color);
void			render_fractal(t_fractal *fractal);
t_complex		pixel_to_complex(t_fractal *fractal, int x, int y);
int				mandelbrot_iterations(t_complex c);
int				get_color(int iterations);
int				julia_iterations(t_complex z, t_fractal *fractal);
int				handle_zoom(int button, int x, int y, t_fractal *fractal);
double			ft_atod(const char *str);
int				is_valid_double(char *str);
void			destroy_fractal(t_fractal *fractal);

#endif
