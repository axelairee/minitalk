/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:39:48 by abolea            #+#    #+#             */
/*   Updated: 2024/02/21 13:38:32 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (words);
}

static void	*ft_freesplit(char **res)
{
	size_t	col;

	col = 0;
	if (res)
	{
		while (res[col])
			free(res[col++]);
		free(res);
	}
	return (NULL);
}

static size_t	ft_strclen(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] == c)
		i++;
	j = 0;
	while (s[i + j] != c && s[i + j])
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**result;
	size_t	col;

	words = ft_countword(s, c);
	col = 0;
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (col < words)
	{
		while (*s == c)
			s++;
		result[col] = ft_substr(s, 0, ft_strclen(s, c));
		if (!result[col])
			return (ft_freesplit(result));
		s += ft_strclen(s, c);
		col++;
	}
	result[col] = NULL;
	return (result);
}
