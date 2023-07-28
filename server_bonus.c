#include "minitalk.h"

int	g_cpid;

void	handle_cpid(int signal, int *i)
{
	g_cpid <<= 1;
	g_cpid += (signal == SIGUSR1);
	(*i)--;
	if (*i == 32)
		*i = 0;
}

void	handle_sigusr(int signal)
{
	static int	i = 64;
	static int	c = 0;

	if (i > 32)
	{
		handle_cpid(signal, &i);
		return ;
	}
	c <<= 1;
	c += (signal == SIGUSR1);
	i++;
	if (i == 32)
	{
		ft_printf("%c", c);
		i = 0;
		if (c == 0)
		{
			i = 64;
			kill(g_cpid, SIGUSR2);
			g_cpid = 0;
		}
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Server's PID = %d\n", getpid());
	ft_printf("Waiting input from client...\n");
	g_cpid = 0;
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	while (1)
		sleep(1);
	return (0);
}
