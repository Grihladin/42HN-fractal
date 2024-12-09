/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:08:04 by mratke            #+#    #+#             */
/*   Updated: 2024/12/09 18:52:15 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_atoi_double(const char *str)
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
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
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

	line = ft_strdup("\n");
	fd = open("picture", 0);
	while (line != NULL)
	{
		ft_printf("%s", line);
		line = get_next_line(fd);
		free(line);
	}
}
