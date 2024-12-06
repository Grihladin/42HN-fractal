/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:34:34 by mratke            #+#    #+#             */
/*   Updated: 2024/12/06 23:50:56 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../ft_printf/ft_printf.h"
# include "MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_fractal
{
	int			f_name;
	int			x;
	int			y;
	int			max_i;
	double		z_real;
	double		z_imag;
	double		c_real;
	double		c_imag;
	double		zoom;
	double		x_center;
	double		y_center;
	mlx_t		*mlx;
	mlx_image_t	*image;
}				t_fractal;

typedef struct s_rgb
{
	int			red;
	int			green;
	int			blue;
}				t_rgb;

// mlx_functions
t_fractal		make_a_picture(t_fractal f);
void			ft_hook(void *param);

// mandelbrot

t_fractal		mandelbrot_init(void);
void			draw_mandelbrot_pixel(t_fractal v);
void			print_mandelbrot(t_fractal v);
// // juia
t_fractal		julia_init(void);
void			draw_julia_pixel(t_fractal v);
void			print_julia(t_fractal v);
void			scroll_callback_ft(double x_delta, double y_delta,
					t_fractal *f);
#endif
