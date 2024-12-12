/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:59:29 by mratke            #+#    #+#             */
/*   Updated: 2024/10/21 18:51:20 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexadecimal(unsigned int n, int type)
{
	char			convert;
	unsigned int	n_len;
	int				upper_or_lower;
	int				tmp;

	tmp = 0;
	upper_or_lower = 'a';
	if (type == 'X')
		upper_or_lower = 'A';
	n_len = 0;
	if (n >= 16)
	{
		tmp = ft_printf_hexadecimal(n / 16, type);
		if (tmp == -1)
			return (-1);
		n_len += tmp;
	}
	if ((n % 16) < 10)
		convert = (n % 16) + '0';
	else
		convert = ((n % 16) - 10) + upper_or_lower;
	if (ft_printf_char(convert) == -1)
		return (-1);
	return (n_len + 1);
}
