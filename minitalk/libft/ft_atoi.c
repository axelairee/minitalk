/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:20:29 by abolea            #+#    #+#             */
/*   Updated: 2023/11/21 10:27:53 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign *= -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (nb > (LONG_MAX - (*nptr - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(nb * sign));
}
