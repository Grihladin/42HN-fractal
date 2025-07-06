/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:50:11 by mratke            #+#    #+#             */
/*   Updated: 2025/07/06 07:35:47 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractal	make_a_picture(t_fractal f)
{
	f.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!f.mlx)
	{
		ft_printf("%s\n", (mlx_strerror(mlx_errno)));
	}
	f.image = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	if (!f.image)
	{
		mlx_close_window(f.mlx);
		ft_printf("%s\n", (mlx_strerror(mlx_errno)));
	}
	return (f);
}

void	esc_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	scroll_callback_ft(double x_delta, double y_delta, t_fractal *f)
{
	double			x;
	double			current_time;
	static double	time_left;

	current_time = mlx_get_time();
	time_left = 0;
	// Reduced cooldown time for more responsive zooming
	if ((current_time - time_left) < 0.1)
		return ;
	time_left = current_time;
	x = x_delta;
	if (x == -10000000)
		return ;
	if (y_delta > 0)
		f->zoom *= ZOOM_FACTOR;
	else if (y_delta < 0)
		f->zoom /= ZOOM_FACTOR;
	
	if (f->name == 6)
		print_mandelbrot(*f);
	else
		print_julia(*f);
}
