/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:37:50 by mratke            #+#    #+#             */
/*   Updated: 2024/10/21 18:51:53 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_int(int n)
{
	int		tmp;
	char	convert;
	int		n_len;

	tmp = 0;
	n_len = 0;
	if (n >= 10)
		tmp = ft_printf_int(n / 10);
	if (tmp == -1)
		return (-1);
	n_len += tmp;
	convert = (n % 10) + '0';
	if (ft_printf_char(convert) == -1)
		return (-1);
	return (n_len + 1);
}

int	ft_printf_int(int n)
{
	int	n_len;

	n_len = 0;
	if (n == -2147483648)
	{
		if (ft_printf_str("-2147483648") == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		if (ft_printf_char('-') == -1)
			return (-1);
		n_len = 1;
	}
	n_len += print_int(n);
	return (n_len);
}
