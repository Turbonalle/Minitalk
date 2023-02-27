/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:51:35 by jbagger           #+#    #+#             */
/*   Updated: 2023/02/27 13:27:39 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// write()	usleep()
#include <stdio.h>	// printf()
#include <string.h>	// strlen()
#include <stdlib.h>	// atoi()
#include <signal.h>	// kill()
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

int	send_bits_int(unsigned int n, pid_t pid, unsigned int len, int bits)
{
	int	bit;

	bit = 1;
	while (bits-- > 0)
	{
		if ((n & bit))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Error!\n", 7);
				return (0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Error!\n", 7);
				return (0);
			}
		}
		usleep(400 + ((len / 30) * 50));
		bit <<= 1;
	}
	return (1);
}

int	send_bits_char(char c, pid_t pid)
{
	int	bit;

	bit = 128;
	while (bit)
	{
		if ((bit & c))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Error!\n", 7);
				return (0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Error!\n", 7);
				return (0);
			}
		}
		usleep(200);
		bit >>= 1;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	pid_t			pid;
	unsigned int	len;
	unsigned int	i;

	if (ac != 3)
	{
		write(2, "Expected input: [./client] [message] [pid]\n", 43);
		return (0);
	}
	pid = atoi(av[2]);
	len = ft_strlen(av[1]);
	send_bits_int(len, pid, len, 32);
	i = 0;
	while (av[1][i])
	{
		if (!send_bits_char(av[1][i], pid))
			return (0);
		i++;
	}
	send_bits_char('\0', pid);
	return (0);
}
