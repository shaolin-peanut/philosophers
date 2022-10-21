/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:28:11 by sbars             #+#    #+#             */
/*   Updated: 2022/08/24 16:14:28 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long int	return_time(void)
{
	long int		ret;
	struct timeval	tp;

	ret = 0;
	if (gettimeofday(&tp, NULL) == -1)
	{
		write(1, "gettimeofday failure\n", 8);
		exit(EXIT_FAILURE);
	}
	ret = (tp.tv_usec / 1000) + (tp.tv_sec * 1000);
	return (ret);
}

// Check if the range between now and last_meal is egal or superior to the
// time_to_die given as first argument
int	dead(t_philo *philo)
{
	if ((return_time() - philo->last_meal) >= philo->pkg->t2die)
		return (1);
	else
		return (0);
}

void	ft_putstr(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		num = n % 10;
		ft_putchar_fd(num + 48, fd);
	}
}
