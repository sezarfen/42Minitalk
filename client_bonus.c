#include "minitalk.h"

int	g_char;

void	get_message(int signal)
{
	(void)signal;
	ft_printf("I receive a message!\n");
}

void	send_pid(int my_pid, int server_pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if ((0x80000000 & my_pid) == 0x80000000)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		i++;
		my_pid <<= 1;
		usleep(30);
	}
}

void	send_char(int pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if ((0x80000000 & g_char) == 0x80000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		g_char <<= 1;
		i++;
		usleep(30);
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
	g_char = '\0';
	send_char(pid);
}

int	main(int ac, char **av)
{
	int		server_pid;
	int		my_pid;

	signal(SIGUSR2, get_message);
	if (ac == 3)
	{
		my_pid = getpid();
		server_pid = ft_atoi(av[1]);
		g_char = 0;
		send_pid(my_pid, server_pid);
		send_string(av[2], server_pid);
	}
	else
	{
		ft_printf("Please use correct format './client [PID] [Char Sequence]'");
		return (1);
	}
	return (0);
}
