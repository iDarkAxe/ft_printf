/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:12:07 by ppontet           #+#    #+#             */
/*   Updated: 2024/11/24 16:53:13 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

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
 *
 * @param n number to print
 * @param fd file descriptor
 * @return ssize_t number of char printed
 */
ssize_t	ft_putnbr_fd(long long n, int fd)
{
	ssize_t count_printed = 0;
	char temp;

	if (n < 0)
	{
		if (n == -2147483648)  
			return (write(fd, "-2147483648", 11));
		else
		{
			n = -n;
			count_printed += write(fd, "-", 1);
		}
	}
	if (n >= 10)
		count_printed += ft_putnbr_fd(n / 10, fd);
	temp = n % 10 + '0';
	count_printed += write(fd, &temp, 1);

	return (count_printed);
}
