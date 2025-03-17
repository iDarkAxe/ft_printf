/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:31:04 by ppontet           #+#    #+#             */
/*   Updated: 2025/03/17 14:48:11 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/**
 * @brief Putnbr with a particular base
 *
 * @param nbr Number to be printed
 * @param base Base to be used
 * @param fd File descriptor
 * @return ssize_t number of char printed
 */
static ssize_t	ft_putnbr_hex_start(unsigned int nbr, const char *base, int fd)
{
	ssize_t	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_putnbr_hex_start(nbr / 16, base, fd);
		count += ft_putnbr_hex_start(nbr % 16, base, fd);
	}
	else
		count += write(fd, &base[nbr], 1);
	return (count);
}

/**
 * @brief Putnbr for hex or HEX
 *
 * @param nbr Number to be printed
 * @param height 'x' or 'X'
 */
ssize_t	ft_putnbr_hex(unsigned int nbr, char height, int fd)
{
	if (height == 1 || height == 'x')
		return (ft_putnbr_hex_start(nbr, "0123456789abcdef", fd));
	else
		return (ft_putnbr_hex_start(nbr, "0123456789ABCDEF", fd));
}

/**
 * @brief Putnbr with a particular base
 *
 * @param nbr Number to be printed
 * @param base Base to be used
 * @param fd File descriptor
 * @return ssize_t number of char printed
 */
static ssize_t	ft_putnbr_hex_pointer(unsigned long nbr, const char *base,
		int fd)
{
	ssize_t	temp;

	temp = 0;
	if (nbr >= 16)
	{
		temp += ft_putnbr_hex_pointer(nbr / 16, base, fd);
		temp += ft_putnbr_hex_pointer(nbr % 16, base, fd);
	}
	else
		temp += write(fd, &base[nbr], 1);
	return (temp);
}

/**
 * @brief Print pointer adress
 *
 * @param nbr Number to be printed
 * @param fd File descriptor
 * @return ssize_t number of char printed
 */
ssize_t	ft_putpointer_fd(unsigned long nbr, int fd)
{
	if (!nbr)
		return (write(fd, "(nil)", 5));
	if (write(fd, "0x", 2) != -1)
		return (ft_putnbr_hex_pointer(nbr, "0123456789abcdef\0", fd) + 2);
	return (-1);
}
