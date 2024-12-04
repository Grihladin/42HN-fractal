/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:34:34 by mratke            #+#    #+#             */
/*   Updated: 2024/12/04 19:57:02 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 512
# define HEIGHT 512

typedef struct s_fractol
{
	int			x;
	int			y;
	int			max_i;
	double		z_real;
	double		z_imag;
	double		c_real;
	double		c_imag;

}				t_fractol;

typedef struct s_draw_lib
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}				t_draw_lib;

#endif
