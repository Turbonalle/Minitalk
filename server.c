#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <signal.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_join_str_with_char(const char *s1, char c)
{
	char	*joined_str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1) + 1;
	joined_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!joined_str)
		return (NULL);
	i = 0;
	while (*s1)
		joined_str[i++] = *s1++;
	joined_str[i++] = c;
	joined_str[i] = 0;
	return (joined_str);
}

void handler(int signal)
{
    static int i = 0;
    static unsigned char c = 0;
	static char *str;
	int j;

	c <<= 1;
    if (signal == SIGUSR1)
		c++;
    i++;
	if (i == 8)
	{
		str = ft_join_str_with_char(str, c);
		if (!c)
		{
			printf("%s\n", str); // FT!!!!!!!!
			j = 0;
			while (str[j])
			{
				str[j] = 0;
				j++;
			}
		}
        i = 0;
        c = 0;
    }
}

int main(void)
{
	struct sigaction action;
	int pid;

	sigemptyset(&action.sa_mask);
	action.sa_handler = handler;
	pid = getpid();
	printf("pid = %d\n", pid);
	while (42)
	{
		
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
