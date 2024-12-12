/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:06:56 by mratke            #+#    #+#             */
/*   Updated: 2024/10/21 16:57:18 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pointer(unsigned long int n)
{
	char	convert;
	int		n_len;

	n_len = 0;
	if (n >= 16)
		n_len += print_pointer(n / 16);
	if ((n % 16) < 10)
	{
		convert = (n % 16) + '0';
	}
	else
	{
		convert = ((n % 16) - 10) + 'a';
	}
	ft_printf_char(convert);
	return (n_len + 1);
}

int	ft_printf_ptr(void *ptr)
{
	int	ptr_len;

	ptr_len = 0;
	if (ptr == NULL)
		return (ft_printf_str("0x0"));
	else
	{
		ptr_len += ft_printf_str("0x");
		if (ptr_len == -1)
			return (-1);
		ptr_len += print_pointer((unsigned long int)ptr);
		return (ptr_len);
	}
}
