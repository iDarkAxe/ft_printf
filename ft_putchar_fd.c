/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:09:32 by ppontet           #+#    #+#             */
/*   Updated: 2024/11/20 21:30:56 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Ecrit le caractere 'c' sur le descripteur de fichier
 *
 * @param c character
 * @param fd file descriptor
 * @return ssize_t number of char printed
 */
ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
