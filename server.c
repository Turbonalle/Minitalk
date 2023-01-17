#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

/*

- Read in blocks of 8.
	- Create a linked list node for each block read.
- If '11111111' is read 4 times in a row:
	- Decode the blocks before that.
	- 'n' = the decoded number.
- Malloc 'n' bytes.
- Read blocks of 8 'n' times.
	- Decode each block into a character.
	- Copy character into string.
- Print string.
*/



void handler(int signal)
{
    static int i = 0;
    static unsigned char c = 0;

    c <<= 1;
    if (signal == SIGUSR1)
		c++;
    i++;
	if (i == 8)
	{
		write(1, &c, 1);
        i = 0;
        c = 0;
    }
}



// void handler(int signal)
// {
//     static int i = 0;
//     static unsigned char c = 0;

//     c <<= 1;
//     if (signal == SIGUSR1)
// 		c++;
//     i++;
// 	if (i == 8)
// 	{
// 		write(1, &c, 1);
//         i = 0;
//         c = 0;
//     }
// }



int main(void)
{
	struct sigaction action;
	int pid;

	sigemptyset(&action.sa_mask); // What does this do?
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

/*
MAX_INT
11111111111111111111111111111111	(4 * 8)
*/