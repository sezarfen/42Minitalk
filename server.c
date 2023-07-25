#include "minitalk.h"

t_result g_handle;

void	handle_siguser1(void)
{
	g_handle.c <<= 1;
	g_handle.c += 1;
	g_handle.used++;
	if (g_handle.used == 8)
	{
		ft_printf("%c", g_handle.c);
		g_handle.used = 0;
		g_handle.c = 0;
	}
}

void	handle_siguser2(void)
{
	g_handle.c <<= 1;
	g_handle.used++;
	if (g_handle.used == 8) // 8 will be read UNICODE chars
	{
		ft_printf("%c", g_handle.c);
		g_handle.used = 0;
		g_handle.c = 0;
	}
}

int	main(void)
{
	ft_printf("Server's PID = %d\n", getpid());
	ft_printf("Waiting input from client...\n");
	g_handle.c = 0;
	g_handle.used = 0;
	signal(SIGUSR1, handle_siguser1);
	signal(SIGUSR2, handle_siguser2);
	while (1)
		sleep(1);
	return (0);
}
