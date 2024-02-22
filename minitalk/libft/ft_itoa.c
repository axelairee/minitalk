/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:04:38 by abolea            #+#    #+#             */
/*   Updated: 2023/11/21 13:18:54 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findnb(int n)
{
	int	nb;

	nb = 0;
	if (n < 0)
		n = n * -1;
	if (n == 0)
		nb = 1;
	while (n != 0)
	{
		n = n / 10;
		nb += 1;
	}
	return (nb);
}

static char	*ft_strrev(char *s)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
		i++;
		j--;
	}
	return (s);
}

static char	*ft_fill_res(char *result, int i, int n, int nb_finder)
{
	while (nb_finder > i)
	{
		result[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		nb_finder;
	char	*result;
	int		i;
	int		tmp;

	i = 0;
	tmp = n;
	nb_finder = ft_findnb(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		result = ft_calloc((nb_finder + 2), sizeof(char));
		n = n * -1;
	}
	else
		result = ft_calloc((nb_finder + 1), sizeof(char));
	if (!result)
		return (NULL);
	result = ft_fill_res(result, i, n, nb_finder);
	if (tmp < 0)
		result[nb_finder] = '-';
	return (ft_strrev(result));
}
