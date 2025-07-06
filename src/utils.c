/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:08:04 by mratke            #+#    #+#             */
/*   Updated: 2025/07/06 09:10:31 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_atoi	init_atoi_v(void)
{
	t_atoi	res;

	res.i = 0;
	res.sign = 1.0;
	res.divisor = 10.0;
	res.result = 0;
	return (res);
}

double	ft_atoi_double(const char *str, t_atoi v)
{
	while ((str[v.i] >= 9 && str[v.i] <= 13) || str[v.i] == 32)
		v.i++;
	if (str[v.i] == '-' || str[v.i] == '+')
	{
		if (str[v.i] == '-')
			v.sign = -1.0;
		v.i++;
	}
	while (str[v.i] >= '0' && str[v.i] <= '9')
	{
		v.result = (v.result * 10.0) + (str[v.i] - '0');
		v.i++;
	}
	if (str[v.i] == '.')
	{
		v.i++;
		while (str[v.i] >= '0' && str[v.i] <= '9')
		{
			v.result += (str[v.i] - '0') / v.divisor;
			v.divisor *= 10.0;
			v.i++;
		}
	}
	return (v.result * v.sign);
}

t_fractal	get_input(char **argv, t_fractal f)
{
	if (argv[1][0] == '1')
		f = julia_init(argv);
	else if (argv[1][0] == '2')
		f = octopus_init();
	else if (argv[1][0] == '3')
		f = medusa_init();
	else if (argv[1][0] == '4')
		f = snowflake_init();
	else if (argv[1][0] == '5')
		f = galaxy_init();
	else if (argv[1][0] == '6')
		f = mandelbrot_init();
	return (f);
}

void	print_fractal(t_fractal f)
{
	if (f.name == 6)
		print_mandelbrot(f);
	else
		print_julia(f);
}

void	welcome_page(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("picture.c", 0);
	while (i < 12)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("%s", line + 2);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
