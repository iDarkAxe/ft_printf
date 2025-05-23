/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:12:07 by ppontet           #+#    #+#             */
/*   Updated: 2025/05/10 10:43:01 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/**
 * @brief Write the string 's' on the given file descriptor
 *
 * @param s string
 * @param fd file descriptor
 * @return ssize_t number of char printed
 */
ssize_t	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

/**
 * @brief Write the character 'c' on the given file descriptor
 *
 * @param c character
 * @param fd file descriptor
 * @return ssize_t number of char printed
 */
ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * @brief Write the int 'n' on the given file descriptor
 *	Works with recursion
 * @param n number to print
 * @param fd file descriptor
 * @return ssize_t number of char printed
 */
static ssize_t	ft_putnbr_recursive_fd(long long n, int fd)
{
	ssize_t	count_printed;
	ssize_t	count_printed_temp;
	char	temp;

	count_printed = 0;
	if (n >= 10)
	{
		count_printed = ft_putnbr_fd(n / 10, fd);
		if (count_printed < 0)
			return (count_printed);
	}
	temp = n % 10 + '0';
	count_printed_temp = write(fd, &temp, 1);
	if (count_printed_temp < 0)
		return (count_printed_temp);
	return (count_printed + count_printed_temp);
}

/**
 * @brief Write the int 'n' on the given file descriptor
 *
 * @param n number to print
 * @param fd file descriptor
 * @return ssize_t number of char printed
 */
ssize_t	ft_putnbr_fd(long long n, int fd)
{
	ssize_t	count_printed;
	ssize_t	count_printed_temp;

	count_printed = 0;
	if (n < 0)
	{
		n = -n;
		count_printed = write(fd, "-", 1);
		if (count_printed < 0)
			return (count_printed);
	}
	count_printed_temp = ft_putnbr_recursive_fd(n, fd);
	if (count_printed_temp < 0)
		return (count_printed_temp);
	return (count_printed + count_printed_temp);
}
