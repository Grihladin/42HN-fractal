/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:50:11 by mratke            #+#    #+#             */
/*   Updated: 2024/12/08 20:17:12 by mratke           ###   ########.fr       */
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
	}
	else if (y_delta < 0)
	{
		f->zoom *= 0.8;
	}
	if (f->f_name == 1)
		print_julia(*f);
	else if (f->f_name == 2)
		print_mandelbrot(*f);
}

t_fractal	get_input(char **argv, t_fractal f)
{
	if (argv[1][0] == '1')
	{
		f.f_name = 1;
		f.c_real = -0.8;
		f.c_imag = 0.156;
		f = julia_init();
	}
	else if (argv[1][0] == '2')
	{
		f.f_name = 2;
		f = mandelbrot_init();
	}
	return (f);
}
void	draw_picture(void)
{
	int		fd;
	char	*line;

	line = ft_strdup("\n");
	fd = open("picture", 0);
	while (line != NULL)
	{
		ft_printf("%s", line);
		line = get_next_line(fd);
		free(line);
	}
}
double	ft_atoi(const char *str)
{
	size_t	i;
	double	sign;
	double	result;
	double	divisor;

	divisor = 10.0;
	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1.0;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i] - '0') / divisor;
			divisor *= 10.0;
			i++;
		}
	}
	return (result * sign);
}
