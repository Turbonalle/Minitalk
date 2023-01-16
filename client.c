#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

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
		usleep(500);
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
		printf("./client \"pid\" \"message\"\n");
		return (0);
	}
	pid = atoi(av[1]);
	while (av[2][i])
	{
		binarify(av[2][i], pid);
		i++;
	}
	return (0);
}