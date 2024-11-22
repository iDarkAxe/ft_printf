/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:35:19 by ppontet           #+#    #+#             */
/*   Updated: 2024/11/22 11:10:34 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Len of string
 *
 * @param the_string
 * @return size_t len
 */
size_t	ft_strlen(const char *the_string)
{
	size_t	count;

	count = 0;
	while (the_string[count] != '\0')
		count++;
	return (count);
}
