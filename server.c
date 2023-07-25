#include "minitalk.h"
// server
/*

	The server must be started first. After its launch, it has to print its PID.

	The communication between your client and your server has to be done only using
	UNIX signals.

*/
result handle;

void	handle_siguser1()
{
	if (handle.c > 127)
		handle.c = 0;
	handle.c <<= 1;
	handle.c += 1;
	handle.used++;
	if (handle.used == 8)
	{
		ft_printf("%c", handle.c);
		handle.used = 0;
	}
}

void	handle_siguser2()
{
	if (handle.c > 127)
		handle.c = 0;
	handle.c <<= 1;
	handle.used++;
	if (handle.used == 8)
	{
		ft_printf("%c", handle.c);
		handle.used = 0;
	}
}

int main(void)
{
	ft_printf("Server's PID = %d\n", getpid());
	ft_printf("Waiting input from client...\n");
	handle.c = 0;
	handle.used = 0;
	signal(SIGUSR1, handle_siguser1);
	signal(SIGUSR2, handle_siguser2);
	while (1)
		sleep(1);
	return (0);
}