/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:37:39 by mratke            #+#    #+#             */
/*   Updated: 2024/12/09 19:43:29 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractal	julia_init(char **argv)
{
	t_fractal	var;

	var.x = 0;
	var.y = 0;
	var.max_i = 70;
	var.z_real = 0;
	var.z_imag = 0;
	var.c_real = ft_atoi_double(argv[2], init_atoi_v());
	var.c_imag = ft_atoi_double(argv[3], init_atoi_v());
	var.zoom = 1;
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

void	print_julia(t_fractal v)
{
	while (v.y < HEIGHT)
	{
		while (v.x < WIDTH)
		{
			draw_julia_pixel(v);
			v.x++;
		}
		v.x = 0;
		v.y++;
	}
}
