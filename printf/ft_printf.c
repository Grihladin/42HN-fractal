/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:54:32 by mratke            #+#    #+#             */
/*   Updated: 2024/10/21 22:16:08 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_format_definer(const char *format, int i, va_list args)
{
	if (format[i] == 'c')
		return (ft_printf_char((char)va_arg(args, int)));
	else if (format[i] == 's')
		return (ft_printf_str(va_arg(args, char *)));
	else if (format[i] == 'i' || format[i] == 'd')
		return (ft_printf_int(va_arg(args, int)));
	else if (format[i] == 'u')
		return (ft_printf_uint(va_arg(args, unsigned int)));
	else if (format[i] == 'p')
		return (ft_printf_ptr(va_arg(args, void *)));
	else if (format[i] == 'x' || format[i] == 'X')
		return (ft_printf_hexadecimal(va_arg(args, unsigned int), format[i]));
	return (0);
}

static int	line_saver(int *i, int current_len)
{
	(*i)++;
	return (current_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_len;
	int		current_len;

	i = 0;
	printed_len = 0;
	current_len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0' && format[i + 1] != '%')
		{
			i++;
			current_len = ft_printf_format_definer(format, i, args);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
			current_len = ft_printf_percent(&i);
		else
			current_len = ft_printf_char(format[i]);
		if (current_len == -1)
			return (-1);
		printed_len += line_saver(&i, current_len);
	}
	return (va_end(args), printed_len);
}

// int	main(void)
// {
// 	int	p_real;
// 	int	p_my;

// 	p_real = printf("%p", "");
// 	printf("\n");
// 	p_my = ft_printf("%p", "");
// 	printf("\n");
// 	printf("my: %i, real: %i", p_my, p_real);
// }
