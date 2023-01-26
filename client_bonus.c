#include <unistd.h>	// write()	usleep()
#include <stdio.h>	// printf()
#include <string.h>	// strlen()
#include <stdlib.h>	// atoi()
#include <signal.h>	// kill()

int binarify(char c, pid_t pid)
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

void handler(int signal)
{
	
}

int main(int ac, char *av[])
{
	struct sigaction action;
	pid_t pid_server;
	pid_t pid_client;
	int i;

	sigemptyset(&action.sa_mask);
	action.sa_handler = handler;
	pid_client = getpid();
	if (ac != 3)
	{
		printf("./client \"message\" \"pid\"\n");
		return (0);
	}
	pid_server = atoi(av[2]);
	i = 0;
	while (av[1][i])
	{
		binarify(av[1][i], pid_server);
		i++;
	}
	binarify('\0', pid_server);
	return (0);
}