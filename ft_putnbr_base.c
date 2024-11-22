/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:31:04 by ppontet           #+#    #+#             */
/*   Updated: 2024/11/22 18:14:06 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/**
 * @brief Putnbr with a particular base
 *
 * @param nbr
 * @param base
 * @return ssize_t number of char printed
 */
ssize_t	ft_putnbr_hex_start(unsigned long nbr, char *base)
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
		temp += ft_putnbr_hex_start(nb / 16, base);
		temp += ft_putnbr_hex_start(nb % 16, base);
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
ssize_t	ft_putnbr_hex(unsigned long nbr, char height)
{
	if (height == 1 || height == 'x')
		return (ft_putnbr_hex_start(nbr, "0123456789abcdef"));
	else
		return (ft_putnbr_hex_start(nbr, "0123456789ABCDEF"));
}
