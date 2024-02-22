/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:29:26 by abolea            #+#    #+#             */
/*   Updated: 2024/02/22 15:29:34 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_realloc(void *s, int size)
{
	void	*tmp;

	if (size == 0)
	{
		free(s);
		return (NULL);
	}
	tmp = malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, s, size);
	free(s);
	return (tmp);
}

void	signal_handler(int signal)
{
	static unsigned char	c = 0;
	static char				*str = NULL;
	static int				bit_count = 0;
	static int				i = 0;
	char					*tmp;

	c <<= 1;
	if (signal == SIGUSR1)
		c |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
		{
			ft_putstr_fd(str, 1);
			write(1, "\n", 1);
			free(str);
			str = NULL;
		}
		else
		{
			tmp = ft_realloc(str, i + 2);
			if (!tmp)
				exit(0);
			str = tmp;
			str[i++] = c;
			str[i] = '\0';
		}
		bit_count = 0;
		c = 0;
	}
}

int	main()
{
	printf("Server PID is : %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
