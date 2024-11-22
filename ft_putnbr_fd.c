/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:16:24 by ppontet           #+#    #+#             */
/*   Updated: 2024/11/20 21:32:10 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Écrit l’entier ’n’ sur le descripteur de fichier donné
 *
 * @param n
 * @param fd
 * @return ssize_t number of char printed
 */
ssize_t	ft_putnbr_fd(int n, int fd)
{
	int		temp;
	ssize_t	count_printed;

	count_printed = 0;
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
	temp = n % 10 + '0';
	if (n >= 10)
	{
		count_printed += ft_putnbr_fd(n / 10, fd);
		count_printed += ft_putnbr_fd(n % 10, fd);
	}
	else
		return (write(fd, &temp, 1));
	return (count_printed);
}
