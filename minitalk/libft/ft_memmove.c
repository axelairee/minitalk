/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:48:51 by abolea            #+#    #+#             */
/*   Updated: 2023/11/20 18:16:35 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (s < d && s + n > d)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
		return (dest);
	}
	if (d >= s + n || s >= d + n || (d < s && d + n > s))
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
