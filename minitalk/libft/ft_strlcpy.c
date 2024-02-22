/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:37:15 by abolea            #+#    #+#             */
/*   Updated: 2023/11/20 18:17:27 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	n = size;
	while (*src != '\0' && n > 1)
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	if (size > 0)
		*dst = '\0';
	while (*src != '\0')
	{
		src++;
		n--;
	}
	return (size - n);
}
