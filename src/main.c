/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:52:55 by mratke            #+#    #+#             */
/*   Updated: 2025/07/06 09:10:05 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	fractal = (t_fractal){0};
	welcome_page();
	if (validate_input(argc, argv) == 0)
	{
		ft_printf("\nINVALID INPUT\n");
		return (1);
	}
	fractal = get_input(argv, fractal);
	fractal = make_a_picture(fractal);
	print_fractal(fractal);
	if (mlx_image_to_window(fractal.mlx, fractal.image, 0, 0) == -1)
	{
		mlx_close_window(fractal.mlx);
		ft_printf("%s\n", (mlx_strerror(mlx_errno)));
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(fractal.mlx, esc_hook, fractal.mlx);
	mlx_scroll_hook(fractal.mlx, (mlx_scrollfunc)scroll_callback_ft, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
