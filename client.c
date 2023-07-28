#include "minitalk.h"

char	g_char;

void	send_char(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((128 & g_char) == 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		g_char <<= 1;
		i++;
		usleep(50);
	}
}

void	send_string(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		g_char = str[i];
		send_char(pid);
		i++;
	}
	g_char = '\n';
	send_char(pid);
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		g_char = 0;
		send_string(av[2], pid);
	}
	else
	{
		ft_printf("Please use correct format './client [PID] [Char Sequence]'");
		return (1);
	}
	return (0);
}
