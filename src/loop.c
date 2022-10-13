/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:27:40 by sbars             #+#    #+#             */
/*   Updated: 2022/08/26 16:20:49 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*ft_loop(t_philo *philo)
{
	//write(1, "hello\n", 6);
	//printf("ms right now%d\n", return_time());
//	while (!death_of_a_philosopher())
//	{
	pick_fork_up(&philo->lfork);
	pick_fork_up(philo->rfork);
	eat(philo, philo->pkg);
	put_fork_down(&philo->lfork);
	put_fork_down(philo->rfork);
	go_sleep(philo, philo->pkg);
	think(philo, philo->pkg);
		//sleep
		//think
//	}
	return (NULL);
}

void	eat(t_philo	*philo, t_data *pkg)
{
	pthread_mutex_lock(&pkg->print_lock);
	print_current_time();
	ft_putnbr_fd(philo->number, 1);
	ft_putstr(" is eating\n");
	pthread_mutex_unlock(&pkg->print_lock);
	ft_usleep(pkg->t2eat);
}

void	go_sleep(t_philo *philo, t_data *pkg)
{
	pthread_mutex_lock(&pkg->print_lock);
	print_current_time();
	ft_putnbr_fd(philo->number, 1);
	ft_putstr(" is sleeping\n");
	pthread_mutex_unlock(&pkg->print_lock);
	ft_usleep(pkg->t2sleep);
}

void	think(t_philo *philo, t_data *pkg)
{
	pthread_mutex_lock(&pkg->print_lock);
	print_current_time();
	ft_putnbr_fd(philo->number, 1);
	ft_putstr(" is thinking\n");
	pthread_mutex_unlock(&pkg->print_lock);
}

void	pick_fork_up(pthread_mutex_t *m)
{
	pthread_mutex_lock(m);
}

void	put_fork_down(pthread_mutex_t *m)
{
	pthread_mutex_unlock(m);
}
