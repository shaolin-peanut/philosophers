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
	while (!dead(philo))
	{
		pthread_create(&philo->death_id, NULL, (void *) death_monitor, philo);
		routine(philo);
		pthread_detach(philo->death_id);
		// if (number of times philo ate == times philo must eat)
			// note it somewhere... if all philos have now eaten enough, the simulation ends here
	}
	return (NULL);
}

void	eat(t_philo	*philo, t_data *pkg)
{
	philo_says("is eating\n", philo);
	philo->last_meal = return_time();
	ft_usleep(pkg->t2eat);
}

void	go_sleep(t_philo *philo, t_data *pkg)
{
	philo_says("is sleeping\n", philo);
	ft_usleep(pkg->t2sleep);
}

void	think(t_philo *philo, t_data *pkg)
{
	philo_says("is thinking\n", philo);
	pthread_mutex_lock(&pkg->print_lock);
	print_current_time();
	ft_putnbr_fd(philo->number, 1);
	ft_putstr(" is thinking\n");
	pthread_mutex_unlock(&pkg->print_lock);
}

void	pick_fork_up(pthread_mutex_t *m, t_philo *philo)
{
	pthread_mutex_lock(m);
	philo_says("has taken a fork\n", philo);
}

void	put_fork_down(pthread_mutex_t *m, t_philo *philo)
{
	(void) philo;
	pthread_mutex_unlock(m);
}
