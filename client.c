#include <unistd.h>	// write()	usleep()
#include <stdio.h>	// printf()
#include <string.h>	// strlen()
#include <stdlib.h>	// atoi()
#include <signal.h>	// kill()

char *ft_itoa(int num)
{
	char *str;
	int temp;
	int len;

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



int main(int ac, char *av[])
{
	pid_t pid;
	char *num;
	int len;
	int i;

	if (ac != 3)
	{
		printf("./client \"pid\" \"message\"\n");
		return (0);
	}
	pid = atoi(av[2]);
	len = strlen(av[1]);
	num = ft_itoa(len);
	i = 0;
	while (num[i] != '\0')
	{
		binarify(num[i], pid);
		printf("num[%d] = %c\n", i, num[i]);
		i++;
	}
	while (i < 32)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			write(2, "Error!\n", 7);
			return (0);
		}
		i++;
	}
	i = 0;
	while (av[1][i])
	{
		binarify(av[1][i], pid);
		i++;
	}
	return (0);
}