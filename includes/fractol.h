/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:34:34 by mratke            #+#    #+#             */
/*   Updated: 2024/12/04 22:09:54 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_fractal
{
	int			x;
	int			y;
	int			max_i;
	double		z_real;
	double		z_imag;
	double		c_real;
	double		c_imag;
	int *histogram;   // Array to store iteration counts
	int *hues;        // Array for normalized hue values
	int total_pixels; // Total pixels outside set
}				t_fractal;

typedef struct s_draw_lib
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}				t_draw_lib;

typedef struct s_rgb
{
	int			red;
	int			green;
	int			blue;
}				t_rgb;

// mlx_functions
t_draw_lib		make_a_picture(void);

// mandelbrot
t_fractal		mandelbrot_init(void);
void			draw_mandelbrot_pixel(t_draw_lib draw_v, t_fractal v);
void			print_mandelbrot(t_draw_lib draw_vars, t_fractal v);

// histogram functions
void			build_histogram(t_fractal *f, mlx_image_t *img);
uint32_t		get_histogram_color(t_fractal *f, int iterations);

#endif
