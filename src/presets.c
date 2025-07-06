/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:24:41 by mratke            #+#    #+#             */
/*   Updated: 2025/07/06 09:10:27 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_fractal	octopus_init(void)
{
	t_fractal	var;

	var.x = 0;
	var.y = 0;
	var.max_i = 100;
	var.z_real = 0;
	var.z_imag = 0;
	var.c_real = -0.8;
	var.c_imag = 0.156;
	var.zoom = 1;
	var.name = 2;
	return (var);
}

t_fractal	medusa_init(void)
{
	t_fractal	var;

	var.x = 0;
	var.y = 0;
	var.max_i = 70;
	var.z_real = 0;
	var.z_imag = 0;
	var.c_real = 0.285;
	var.c_imag = 0;
	var.zoom = 1;
	var.name = 3;
	return (var);
}

t_fractal	snowflake_init(void)
{
	t_fractal	var;

	var.x = 0;
	var.y = 0;
	var.max_i = 70;
	var.z_real = 0;
	var.z_imag = 0;
	var.c_real = -0.70176;
	var.c_imag = 0.3842;
	var.zoom = 1;
	var.name = 4;
	return (var);
}

t_fractal	galaxy_init(void)
{
	t_fractal	var;

	var.x = 0;
	var.y = 0;
	var.max_i = 500;
	var.z_real = 0;
	var.z_imag = 0;
	var.c_real = -0.7269;
	var.c_imag = 0.1889;
	var.zoom = 1;
	var.name = 5;
	return (var);
}
