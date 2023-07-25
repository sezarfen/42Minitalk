#include "minitalk.h"
// client

/*
	The client takes two parameters:
		◦ The server PID.
		◦ The string to send  // ac == 3
*/
char	a;

void	send_signal(int pid)
{
	int	i;
	
	// 128 -> 1000 0000 & .... -> 128 ya da 0 verecektir
	i = 0;
	while (i < 8)
	{
		if ((128 & a) == 128) // 1000 0000 & ..... -> 1000 0000 case ' i geldiyse karşıda + 1 yap
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		a <<= 1;
		usleep(30);
	}
}

void	send_string(char *str, int pid)
{
	int		i;

	i = 0;
	while (str[i])
	{
		a = str[i];
		send_signal(pid);
		i++;
	}
	a = '\n';
	send_signal(pid);
}

int main(int ac, char **av)
{
	int		pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_string(av[2], pid);
	}
	else
	{
		ft_printf("Please use correct format './client [PID] [Char Sequence]'");
		return (1);
	}
	return (0);
}