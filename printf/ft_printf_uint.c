/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:19:39 by mratke            #+#    #+#             */
/*   Updated: 2024/10/21 18:47:04 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_uint(unsigned int n)
{
	char	convert;
	int		n_len;
	int		tmp;

	tmp = 0;
	n_len = 0;
	if (n >= 10)
		tmp = ft_printf_uint(n / 10);
	if (tmp == -1)
		return (-1);
	n_len += tmp;
	convert = (n % 10) + '0';
	if (ft_printf_char(convert) == -1)
		return (-1);
	return (n_len + 1);
}
