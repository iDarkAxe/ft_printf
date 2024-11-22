/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:15:41 by ppontet           #+#    #+#             */
/*   Updated: 2024/11/22 18:14:25 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief Find first occurrence of searched_char
 *
 * @param string
 * @param searched_char
 * @return char* index of Char found
 */
char	*ft_strchr(const char *string, int searched_char)
{
	unsigned long int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (char)searched_char)
			return ((char *)&string[i]);
		i++;
	}
	if (string[i] == (char)searched_char)
		return ((char *)&string[i]);
	return (NULL);
}
