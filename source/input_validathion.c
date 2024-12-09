/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validathion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:33:16 by mratke            #+#    #+#             */
/*   Updated: 2024/12/09 19:27:06 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		result;

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
			sign = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
static int	check_for_notnum(char **argv)
{
	int	i;
	int	j;

	i = 2;
	while (i < 4)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '.'
				|| argv[i][j] == '-')
			{
				j++;
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	validate_input(int argc, char **argv)
{
	int	arg;

	if (argc != 2 && argc != 4)
		return (0);
	if (argc == 2)
	{
		arg = ft_atoi(argv[1]);
		if (arg < 2 || arg > 6)
			return (0);
	}
	else if (argc == 4)
	{
		if (check_for_notnum(argv) == 1 || argv[1][0] != '1')
			return (0);
	}
	return (1);
}
