/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:12:07 by ppontet           #+#    #+#             */
/*   Updated: 2024/11/24 16:00:51 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

/**
 * @brief Écrit la chaîne de caractères ’s’ sur le descripteur de fichier donné
 *
 * @param s string
 * @param fd file descriptor
 * @return ssize_t nombre de caractere qui ont été écrits
 */
ssize_t	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

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

/**
 * @brief Écrit l’entier 'n' sur le descripteur de fichier donné
 *
 * @param n L'entier à écrire
 * @param fd Le descripteur de fichier où écrire
 * @return ssize_t Nombre de caractères imprimés
 */
ssize_t	ft_putnbr_fd(long long n, int fd)
{
	ssize_t count_printed = 0;
	char temp;

	// Si le nombre est négatif, gérer le signe.
	if (n < 0)
	{
		if (n == -2147483648)  // Cas limite pour les int 32 bits
			return (write(fd, "-2147483648", 11));
		else
		{
			n = -n;  // Rendre le nombre positif
			count_printed += write(fd, "-", 1);  // Écrire le signe
		}
	}

	// Cas pour les unsigned (en général)
	if (n >= 10)
	{
		count_printed += ft_putnbr_fd(n / 10, fd);  // Diviser le nombre pour obtenir chaque chiffre
	}
	
	// Récupérer et écrire le dernier chiffre
	temp = n % 10 + '0';  // Convertir le chiffre en caractère
	count_printed += write(fd, &temp, 1);

	return (count_printed);
}
