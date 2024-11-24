/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:31:04 by ppontet           #+#    #+#             */
/*   Updated: 2024/11/24 15:59:14 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/**
 * @brief Putnbr with a particular base
 *
 * @param nbr
 * @param base
 * @return ssize_t number of char printed
 */
static ssize_t	ft_putnbr_hexadecimal(long nbr, char *base)
{
        long	nb;
        ssize_t	temp;

        temp = 0;
        nb = nbr;
        if (nb < 0)
        {
                nb = -nb;
                temp += write(1, "-", 1);
        }
        if (nb >= 16)
        {
            temp += ft_putnbr_hexadecimal(nb / 16, base);
            temp += ft_putnbr_hexadecimal(nb % 16, base);
        }
        else
                temp += write(1, &base[nb], 1);
        return (temp);
}

/**
 * @brief Putnbr for hex or HEX
 *
 * @param nbr
 * @param height
 */
ssize_t	ft_putnbr_hex(long nbr, char height)
{
	if (height == 1 || height == 'x')
		return (ft_putnbr_hexadecimal(nbr, "0123456789abcdef"));
	else
		return (ft_putnbr_hexadecimal(nbr, "0123456789ABCDEF"));
}

/**
 * @brief Putnbr with a particular base
 *
 * @param nbr
 * @param base
 * @return ssize_t number of char printed
 */
static ssize_t	ft_putnbr_hex_pointer(unsigned long nbr, char *base)
{
	ssize_t				temp;
	unsigned long long	nb;

	temp = 0;
	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	if (nb >= 16)
	{
		temp += ft_putnbr_hex_pointer(nb / 16, base);
		temp += ft_putnbr_hex_pointer(nb % 16, base);
	}
	else
		temp += write(1, &base[nb], 1);
	return (temp);
}

/**
 * @brief Print pointer adress
 *
 * @param ptr
 * @return ssize_t
 */
ssize_t	ft_putpointer_fd(unsigned long ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_putnbr_hex_pointer(ptr,
			"0123456789abcdef\0"));
}
