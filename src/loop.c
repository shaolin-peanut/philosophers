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

void	*routine(t_philo *philo)
{
	if (philo->number % 2 == 1)
	{
		pick_fork_up(&philo->lfork, philo);
		pick_fork_up(philo->rfork, philo);
	}
	else if (philo->number % 2 == 0)
	{
		pick_fork_up(philo->rfork, philo);
		pick_fork_up(&philo->lfork, philo);
	}
	eat(philo, philo->pkg);
	put_fork_down(&philo->lfork, philo);
	put_fork_down(philo->rfork, philo);
	go_sleep(philo, philo->pkg);
	think(philo, philo->pkg);
	return (NULL);
}

void	*ft_loop(t_philo *philo)
{
	// write(1, "hello\n", 6);
	// printf("ms right now%d\n", return_time());
	// while (!death_of_a_philosopher())
	// {
	// pthread_mutex_lock(&philo->pkg->print_lock);
	// ft_putnbr_long(philo->pkg->start_time);
	// ft_putstr(" START\n");
	// pthread_mutex_unlock(&philo->pkg->print_lock);
	while (!dead(philo))
	{
		pthread_create(&philo->death_id, NULL, (void *) death_monitor, philo);
		routine(philo);
		pthread_detach(philo->death_id);
	}
	return (NULL);
}

void	eat(t_philo	*philo, t_data *pkg)
{
	// if (dead())
	//		die();
	pthread_mutex_lock(&pkg->print_lock);
	print_current_time();
	ft_putnbr_fd(philo->number, 1);
	ft_putstr(" is eating\n");
	pthread_mutex_unlock(&pkg->print_lock);
	ft_usleep(pkg->t2eat);
}

void	go_sleep(t_philo *philo, t_data *pkg)
{
	// if (dead())
	//		die();
	pthread_mutex_lock(&pkg->print_lock);
	print_current_time();
	ft_putnbr_fd(philo->number, 1);
	ft_putstr(" is sleeping\n");
	pthread_mutex_unlock(&pkg->print_lock);
	ft_usleep(pkg->t2sleep);
}

void	think(t_philo *philo, t_data *pkg)
{
	// if (dead())
	//		die();
	pthread_mutex_lock(&pkg->print_lock);
	print_current_time();
	ft_putnbr_fd(philo->number, 1);
	ft_putstr(" is thinking\n");
	pthread_mutex_unlock(&pkg->print_lock);
}

void	pick_fork_up(pthread_mutex_t *m, t_philo *philo)
{
	// if (dead())
	//		die();
	pthread_mutex_lock(m);
	// above is the actual function's work, below is printing the message...
	// should be abstracted.
	pthread_mutex_lock(&philo->pkg->print_lock);
	print_current_time();
	ft_putnbr_fd(philo->number, 1);
	ft_putstr(" has taken a fork\n");
	pthread_mutex_unlock(&philo->pkg->print_lock);
}

void	put_fork_down(pthread_mutex_t *m, t_philo *philo)
{
	(void) philo;
	pthread_mutex_unlock(m);
/*	pthread_mutex_lock(&philo->pkg->print_lock);
	print_current_time();
	ft_putnbr_fd(philo->number, 1);
	ft_putstr(" put a fork down\n");
	pthread_mutex_unlock(&philo->pkg->print_lock);*/
}
