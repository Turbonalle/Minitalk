/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:51:35 by jbagger           #+#    #+#             */
/*   Updated: 2023/02/21 13:01:33 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// write()	usleep()
#include <stdio.h>	// printf()
#include <string.h>	// strlen()
#include <stdlib.h>	// atoi()
#include <signal.h>	// kill()
#include "ft_printf/ft_printf.h"

char	*ft_itoa(int num)
{
	char	*str;
	int		temp;
	int		len;

	temp = num;
	len = 0;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

int	binarify(char c, pid_t pid)
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
		usleep(100);
		bit >>= 1;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	pid_t	pid;
	int		i;

	// count len, send to binarify, chenge usleep compared to len!!!
	if (ac != 3)
	{
		write(2, "Expected input: [./client] [message] [pid]\n", 43);
		return (0);
	}
	pid = atoi(av[2]);
	i = 0;
	while (av[1][i])
	{
		if (!binarify(av[1][i], pid))
			return (0);
		i++;
	}
	binarify('\0', pid);
	return (0);
}
