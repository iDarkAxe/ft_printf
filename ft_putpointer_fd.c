/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:10:56 by ppontet           #+#    #+#             */
/*   Updated: 2024/11/22 16:42:06 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (write(1, "0x", 2) + ft_putnbr_hex_start(ptr,
			"0123456789abcdef\0"));
}
