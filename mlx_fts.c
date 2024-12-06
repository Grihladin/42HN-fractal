/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:50:11 by mratke            #+#    #+#             */
/*   Updated: 2024/12/06 23:43:27 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

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

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	scroll_callback_ft(double x_delta, double y_delta, t_fractal *f)
{
	double	xxx;

	xxx = x_delta;
	if (y_delta > 0)
	{
		f->zoom *= 1.2;
		ft_printf("zoom in");
	}
	else if (y_delta < 0)
	{
		f->zoom *= 0.8;
		ft_printf("zoom out");
	}
	print_julia(*f);
}
