/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:58:55 by ppontet           #+#    #+#             */
/*   Updated: 2024/11/27 13:11:36 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static ssize_t	ft_print_search(char param, va_list va);
static char		ft_verify_param(char param, char format);

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	ssize_t	write_count;
	size_t	count;

	if (str == NULL || (str != NULL && *str == '%' && *(str + 1) == '\0'))
		return (-1);
	va_start(arg_ptr, str);
	count = 0;
	while (str != NULL && *str != '\0')
	{
		while (*str != '%' && *str != '\0')
			count += ft_putchar_fd(*(str++), 1);
		if (ft_verify_param(*str, *(str + 1)) != 0)
		{
			write_count = ft_print_search(*(str + 1), arg_ptr);
			if (write_count == -1)
				return (-1);
			count += write_count;
			str += 2;
		}
		else if (*str == '%' && ft_verify_param(*str, *(str + 1)) == 0)
			str++;
	}
	va_end(arg_ptr);
	return (count);
}

/**
 * @brief Verify if the param after the percentage exist
 *
 * @param character Should be the percentage
 * @param format
 * @return char returns param if exist in printf, 0 if doesn´t
 */
static char	ft_verify_param(char param, char format)
{
	if (param == '\0' || param != '%' || format == '\0')
		return (0);
	if (format == 'c' || format == 's' || format == 'p' || format == 'd'
		|| format == 'i' || format == 'u' || format == 'x' || format == 'X'
		|| format == '%')
		return (format);
	else if (param == '%')
		return (-1);
	else
		return (0);
}

/**
 * @brief Executes the right function for the right param
 *
 * @param param
 * @param va
 */
static ssize_t	ft_print_search(char param, va_list va)
{
	if (param == '%')
		return (ft_putchar_fd('%', 1));
	if (param == 'c')
		return (ft_putchar_fd(va_arg(va, int), 1));
	if (param == 's')
		return (ft_putstr_fd(va_arg(va, char *), 1));
	if (param == 'p')
		return (ft_putpointer_fd(va_arg(va, long long)));
	if (param == 'd' || param == 'i')
		return (ft_putnbr_fd(va_arg(va, int), 1));
	if (param == 'u')
		return (ft_putnbr_fd(va_arg(va, unsigned int), 1));
	if (param == 'x' || param == 'X')
		return (ft_putnbr_hex(va_arg(va, unsigned int), param));
	return (-1);
}
