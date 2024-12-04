/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:50:11 by mratke            #+#    #+#             */
/*   Updated: 2024/12/04 20:50:42 by mratke           ###   ########.fr       */
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
