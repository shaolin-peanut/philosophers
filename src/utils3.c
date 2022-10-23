/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:01:42 by sbars             #+#    #+#             */
/*   Updated: 2022/10/21 19:29:18 by sbars            ###   ########.fr       */
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
	long int	time;

	time = 0;
	time = return_time() - philo->pkg->start_time;
	check_aliveness_announce_and_exit(philo);
	pthread_mutex_lock(&philo->pkg->print_lock);
	if (philo->pkg->someone_died > 0)
	{
		pthread_mutex_unlock(&philo->pkg->print_lock);
		pthread_exit(NULL);
	}
	ft_putnbr_long(time);
	write(1, " ", 1);
	ft_putnbr_long(philo->number);
	write(1, " ", 1);
	ft_putstr(str);
	pthread_mutex_unlock(&philo->pkg->print_lock);
	check_aliveness_announce_and_exit(philo);
}

int	announce_death(t_philo *philo)
{
	long int	time;

	time = 0;
	time = return_time() - philo->pkg->start_time;
	if (philo->pkg->someone_died > 0)
		pthread_exit(0);
	philo->pkg->someone_died = 1;
	if (pthread_mutex_unlock(&philo->lfork) != 0)
		ft_putstr("unlock error\n");
	if (pthread_mutex_unlock(philo->rfork) != 0)
		ft_putstr("unlock error\n");
	pthread_mutex_destroy(&philo->lfork);
	pthread_mutex_destroy(philo->rfork);
	pthread_mutex_lock(&philo->pkg->print_lock);
	ft_putnbr_long(time);
	write(1, " ", 1);
	ft_putnbr_long(philo->number);
	write(1, " ", 1);
	ft_putstr("died.\n");
	pthread_mutex_unlock(&philo->pkg->print_lock);	
	// free_all(philo->pkg);
	pthread_exit(0);
	return (0);
}
