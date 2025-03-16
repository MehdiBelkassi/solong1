#include <signal.h>
#include <unistd.h>
#include "printf/ft_printf.h"

static int	check_overflow(long int res, int sign, char next_digit)
{
	if (res > (LONG_MAX - (next_digit - '0')) / 10)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	res;
	int			sign;
	int			overflow_check;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		overflow_check = check_overflow(res, sign, str[i]);
		if (overflow_check != 1)
			return (overflow_check);
		res = res * 10 + (str[i++] - '0');
	}
	return (res * sign);
}

void	send_signal(int pid, char c)
{
	int	j;

	j = 0;
	usleep(42);
	while (j++ < 8)
	{
		if (((c >> (8 - j)) & 1) == 1)
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		usleep(255);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc != 3 || ft_atoi(argv[1]) == 0)
	{
		ft_printf ("not a valid input !");
		return (0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		usleep(42);
		i++;
	}
	send_signal(pid, '\0');
}