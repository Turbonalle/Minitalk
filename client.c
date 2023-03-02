/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:51:35 by jbagger           #+#    #+#             */
/*   Updated: 2023/03/02 11:03:11 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

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

int	has_error(int ac, char *av[])
{
	int	i;

	if (ac != 3)
		return (1);
	i = 0;
	while (av[1][i])
	{
		if (!ft_isdigit(av[1][i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	pid_t			pid;
	unsigned int	len;
	unsigned int	i;

	if (has_error(ac, av))
	{
		write(2, "Expected input: [./client] [pid] [message]\n", 43);
		return (-1);
	}
	pid = ft_atoi(av[1]);
	len = ft_strlen(av[2]);
	send_bits_int(len, pid, len, 32);
	i = 0;
	while (av[2][i])
	{
		if (!send_bits_char(av[2][i], pid))
			return (0);
		i++;
	}
	send_bits_char('\0', pid);
	return (0);
}
