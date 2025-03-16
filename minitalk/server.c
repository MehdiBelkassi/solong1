
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
// #include "printf/ft_printf.h"

static int	g_cpunter;

void	signal_handler(int signum, siginfo_t *info, void *vd)
{
	static char		result;
	static pid_t	pid;

	(void)vd;
	if (pid == 0)
		pid = info->si_pid;
	if (info->si_pid != pid)
	{
		pid = 0;
		g_cpunter = 0;
		result = 0;
	}
	if (signum == SIGUSR2)
		result |= (0b10000000 >> g_cpunter);
	if (++g_cpunter == 8)
	{
		g_cpunter = 0;
		if (result == '\0')
		{
			write (1, "\n", 1);
			return ;
		}
		write (1, &result, 1);
		result = 0;
	}
}

int	main(void)
{
	struct sigaction	sigg;

	printf("Server PID >  \t%d", getpid());
	sigg.sa_sigaction = signal_handler;
	sigg.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigg, 0);
	sigaction(SIGUSR2, &sigg, 0);
	while (1)
		pause();
	return (0);
}
