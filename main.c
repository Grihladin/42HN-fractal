/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:52:55 by mratke            #+#    #+#             */
/*   Updated: 2024/12/06 23:52:50 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	main(void)
{
	t_fractal	fractal;

	fractal = mandelbrot_init();
	fractal = make_a_picture(fractal);
	print_mandelbrot(fractal);
	if (mlx_image_to_window(fractal.mlx, fractal.image, 0, 0) == -1)
	{
		mlx_close_window(fractal.mlx);
		ft_printf("%s\n", (mlx_strerror(mlx_errno)));
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(fractal.mlx, ft_hook, fractal.mlx);
	mlx_scroll_hook(fractal.mlx, (mlx_scrollfunc)scroll_callback_ft, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
