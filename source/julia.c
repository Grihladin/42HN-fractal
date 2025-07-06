/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:37:39 by mratke            #+#    #+#             */
/*   Updated: 2025/07/06 07:35:47 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractal	julia_init(char **argv)
{
	t_fractal	var;

	var.x = 0;
	var.y = 0;
	var.max_i = MAX_ITERATIONS_DEFAULT;
	var.z_real = 0;
	var.z_imag = 0;
	var.c_real = ft_atoi_double(argv[2], init_atoi_v());
	var.c_imag = ft_atoi_double(argv[3], init_atoi_v());
	var.zoom = 1;
	var.x_center = 0;
	var.y_center = 0;
	var.name = 1;
	return (var);
}

void	draw_julia_pixel(t_fractal v)
{
	int			i;
	double		tmp;
	uint32_t	coulor;
	int			normalised_i;

	v.z_real = (v.x - WIDTH / 2.0) * 4.0 / (WIDTH * v.zoom) + v.x_center;
	v.z_imag = (v.y - HEIGHT / 2.0) * 4.0 / (HEIGHT * v.zoom) + v.y_center;
	i = 0;
	while (i < v.max_i && (v.z_real * v.z_real + v.z_imag * v.z_imag) < 4)
	{
		tmp = v.z_real * v.z_real - v.z_imag * v.z_imag + v.c_real;
		v.z_imag = 2 * v.z_real * v.z_imag + v.c_imag;
		v.z_real = tmp;
		i++;
	}
	normalised_i = (i * 255 / v.max_i);
	if (i == v.max_i)
		coulor = (64 << 24) | (0 << 16) | (64 << 8) | 255;
	else
		coulor = (normalised_i << 24) | (0 << 16) | (normalised_i << 8) | 255;
	mlx_put_pixel(v.image, v.x, v.y, coulor);
}

void	*julia_thread(void *arg)
{
	t_thread_data	*data = (t_thread_data *)arg;
	int				y, x, i, idx;
	double			z_imag, z_real, tmp;

	for (y = data->start_y; y < data->end_y; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			z_real = x * data->real_scale + data->c_real_base;
			z_imag = (y - HEIGHT / 2.0) * data->imag_scale + data->fractal->y_center;
			i = 0;
			
			while (i < data->fractal->max_i && complex_magnitude_sq(z_real, z_imag) < ESCAPE_RADIUS_SQ)
			{
				tmp = z_real * z_real - z_imag * z_imag + data->fractal->c_real;
				z_imag = 2.0 * z_real * z_imag + data->fractal->c_imag;
				z_real = tmp;
				i++;
			}
			
			idx = y * WIDTH + x;
			data->pixels[idx] = calculate_color(i, data->fractal->max_i);
		}
	}
	return (NULL);
}

void	print_julia(t_fractal v)
{
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_data[NUM_THREADS];
	double			real_scale, imag_scale, z_real_base;
	uint32_t		*pixels;
	int				i, rows_per_thread, start_y;

	real_scale = 4.0 / (WIDTH * v.zoom);
	imag_scale = 4.0 / (HEIGHT * v.zoom);
	z_real_base = -WIDTH / 2.0 * real_scale + v.x_center;
	pixels = (uint32_t *)v.image->pixels;
	rows_per_thread = HEIGHT / NUM_THREADS;

	for (i = 0; i < NUM_THREADS; i++)
	{
		start_y = i * rows_per_thread;
		thread_data[i] = (t_thread_data){
			.fractal = &v,
			.start_y = start_y,
			.end_y = (i == NUM_THREADS - 1) ? HEIGHT : start_y + rows_per_thread,
			.pixels = pixels,
			.real_scale = real_scale,
			.imag_scale = imag_scale,
			.c_real_base = z_real_base
		};
		pthread_create(&threads[i], NULL, julia_thread, &thread_data[i]);
	}

	for (i = 0; i < NUM_THREADS; i++)
		pthread_join(threads[i], NULL);
}
