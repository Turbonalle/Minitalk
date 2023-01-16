#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handler(int signal)
{
    static int i = 0;
    static unsigned char c = 0;

    c <<= 1;
    c += signal == SIGUSR1;
    if (++i == 8) {
        write(1, &c, 1);
        i = 0;
        c = 0;
    }
}

// Call handler() function whenever SIGUSR1 or SIGUSR2 signal is recieved.

int main(void)
{
	struct sigaction action;
	int pid;

	action.sa_handler = handler;
	pid = getpid();
	printf("pid = %d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}