/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:52:55 by mratke            #+#    #+#             */
/*   Updated: 2024/12/04 23:20:29 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	main(void)
{
	t_draw_lib	mlx_vars;
	t_fractal	fractal;

	mlx_vars = make_a_picture();
	fractal = mandelbrot_init();
	print_mandelbrot(mlx_vars, fractal);
	if (mlx_image_to_window(mlx_vars.mlx, mlx_vars.image, 0, 0) == -1)
	{
		mlx_close_window(mlx_vars.mlx);
		ft_printf("%s\n", (mlx_strerror(mlx_errno)));
		return (EXIT_FAILURE);
	}
	mlx_loop(mlx_vars.mlx);
	mlx_terminate(mlx_vars.mlx);
	return (EXIT_SUCCESS);
}
