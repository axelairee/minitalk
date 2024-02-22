/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:29:34 by abolea            #+#    #+#             */
/*   Updated: 2024/02/22 11:31:56 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>

void signal_handler(char c, int pid)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		i--;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
	}
}

int main(int argc, char **argv) 
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		printf("Error\n");
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		signal_handler(argv[2][i], pid);
		i++;
	}
	signal_handler('\0', pid);
	return (0);
}
