/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:52:55 by mratke            #+#    #+#             */
/*   Updated: 2024/12/08 20:13:11 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	fractal = (t_fractal){0};
	draw_picture();
	if (argc != 2 && argc != 4)
	{
		ft_printf("INVALID INPUT");
		return (1);
	}
	fractal = get_input(argv, fractal);
	fractal = make_a_picture(fractal);
	if (fractal.f_name == 1)
		print_julia(fractal);
	else if (fractal.f_name == 2)
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
