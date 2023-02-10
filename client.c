#include <unistd.h>	// write()	usleep()
#include <stdio.h>	// printf()
#include <string.h>	// strlen()
#include <stdlib.h>	// atoi()
#include <signal.h>	// kill()
#include "ft_printf/ft_printf.h"

void handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message received!\n");
}

int send_bits(char c, pid_t pid)
{
	int bit;

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
	return (0);
}

int main(int ac, char *av[])
{
	pid_t pid;
	int i;

	if (ac != 3)
	{
		ft_printf("[./client] [message] [server-PID]\n");
		return (0);
	}
	pid = ft_atoi(av[2]);
	i = 0;
	while (av[1][i])
	{
		send_bits(av[1][i], pid);
		i++;
	}
	send_bits('\0', pid);
	return (0);
}