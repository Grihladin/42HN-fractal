/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:52:55 by mratke            #+#    #+#             */
/*   Updated: 2024/12/04 19:57:12 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

t_draw_lib	make_a_picture(void)
{
	t_draw_lib	var;

	var.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!var.mlx)
	{
		puts(mlx_strerror(mlx_errno));
	}
	var.image = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	if (!var.image)
	{
		mlx_close_window(var.mlx);
		puts(mlx_strerror(mlx_errno));
	}
	return (var);
}
t_fractol	mandelbrot_init(void)
{
	t_fractol	var;

	var.x = 0;
	var.y = 0;
	var.max_i = 100;
	var.z_real = 0;
	var.z_imag = 0;
	var.c_real = 0;
	var.c_imag = 0;
	return (var);
}

void	draw_mandelbrot_pixel(t_draw_lib draw_v, t_fractol v)
{
	int			i;
	double		tmp;
	uint32_t	coulor;

	v.z_real = 0;
	v.z_imag = 0;
	i = 0;
	while (i < v.max_i && (v.z_real * v.z_real + v.z_imag * v.z_imag) < 4)
	{
		tmp = v.z_real * v.z_real - v.z_imag * v.z_imag + v.c_real;
		v.z_imag = 2 * v.z_real * v.z_imag + v.c_imag;
		v.z_real = tmp;
		i++;
	}
	if (i == v.max_i)
		coulor = 0xFFFFFFF;
	else
		coulor = ((i * 255 / v.max_i) << 24) | 0xFFFF00FF;
	mlx_put_pixel(draw_v.image, v.x, v.y, coulor);
}

void	print_mandelbrot(t_draw_lib draw_vars, t_fractol v)
{
	while (v.y < HEIGHT)
	{
		while (v.x < WIDTH)
		{
			v.c_real = (v.x - WIDTH / 2.0) * 4.0 / WIDTH;
			v.c_imag = (v.y - HEIGHT / 2.0) * 4.0 / HEIGHT;
			draw_mandelbrot_pixel(draw_vars, v);
			v.x++;
		}
		v.x = 0;
		v.y++;
	}
}
int	main(void)
{
	t_draw_lib	mlx_vars;
	t_fractol	fractal;

	mlx_vars = make_a_picture();
	fractal = mandelbrot_init();
	print_mandelbrot(mlx_vars, fractal);
	if (mlx_image_to_window(mlx_vars.mlx, mlx_vars.image, 0, 0) == -1)
	{
		mlx_close_window(mlx_vars.mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx_loop(mlx_vars.mlx);
	mlx_terminate(mlx_vars.mlx);
	return (EXIT_SUCCESS);
}
