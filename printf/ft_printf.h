/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mratke <mratke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:14:19 by mratke            #+#    #+#             */
/*   Updated: 2024/10/21 22:19:30 by mratke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// includes
# include <stdarg.h> // va_list
# include <unistd.h> //write

// Mandatory part
int	ft_printf(const char *format, ...);
int	ft_printf_char(int c);
int	ft_printf_str(char *s);
int	ft_printf_int(int n);
int	ft_printf_uint(unsigned int n);
int	ft_printf_percent(int *i);
int	ft_printf_ptr(void *ptr);
int	ft_printf_hexadecimal(unsigned int n, int type);
#endif
