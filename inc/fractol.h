/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:34:34 by mratke            #+#    #+#             */
/*   Updated: 2025/07/06 07:35:47 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <ft_printf.h>
# include "MLX42/MLX42.h"
# include <get_next_line.h>
# include <math.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1024
# define HEIGHT 1024
# define NUM_THREADS 8
# define MAX_ITERATIONS_DEFAULT 100
# define ESCAPE_RADIUS_SQ 4.0
# define ZOOM_FACTOR 1.2

static inline double complex_magnitude_sq(double real, double imag)
{
	return real * real + imag * imag;
}

static inline uint32_t calculate_color(int iterations, int max_iterations)
{
	if (iterations == max_iterations)
		return (64 << 24) | (0 << 16) | (64 << 8) | 255;
	else
	{
		int normalized = (iterations * 255 / max_iterations);
		return (normalized << 24) | (0 << 16) | (normalized << 8) | 255;
	}
}

typedef struct s_fractal
{
	int			name;
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

typedef struct s_thread_data
{
	t_fractal	*fractal;
	int			start_y;
	int			end_y;
	uint32_t	*pixels;
	double		real_scale;
	double		imag_scale;
	double		c_real_base;
}				t_thread_data;

typedef struct s_atoi
{
	size_t		i;
	double		sign;
	double		result;
	double		divisor;
}				t_atoi;

// mlx_functions

t_fractal		make_a_picture(t_fractal f);
void			esc_hook(void *param);
void			scroll_callback_ft(double x_delta, double y_delta,
					t_fractal *f);

// utils

void			welcome_page(void);
double			ft_atoi_double(const char *str, t_atoi v);
t_fractal		get_input(char **argv, t_fractal f);
void			print_fractal(t_fractal f);
int				validate_input(int argc, char **argv);
t_atoi			init_atoi_v(void);

// presets

t_fractal		octopus_init(void);
t_fractal		medusa_init(void);
t_fractal		snowflake_init(void);
t_fractal		galaxy_init(void);

// mandelbrot

t_fractal		mandelbrot_init(void);
void			draw_mandelbrot_pixel(t_fractal v);
void			print_mandelbrot(t_fractal v);

// juia

t_fractal		julia_init(char **argv);
void			draw_julia_pixel(t_fractal v);
void			print_julia(t_fractal v);
#endif
