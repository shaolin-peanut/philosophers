/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:01:42 by sbars             #+#    #+#             */
/*   Updated: 2022/08/26 16:19:24 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	print_current_time(void)
{
	ft_putnbr_long(return_time());
	write(1, " ", 1);
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = return_time();
	while ((return_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

void	ft_putnbr_long(long int n)
{
	char	num;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_fd(-n, 1);
	}
	else
	{
		if (n > 9)
			ft_putnbr_long(n / 10);
		num = n % 10;
		ft_putchar_fd(num + 48, 1);
	}
}

void	philo_says(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->pkg->print_lock);
	ft_putnbr_long(return_time());
	write(1, " ", 1);
	ft_putnbr_long(philo->number);
	ft_putstr(str);
	pthread_mutex_unlock(&philo->pkg->print_lock);
}