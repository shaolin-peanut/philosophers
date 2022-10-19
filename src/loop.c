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
	if (philo->pkg->someone_died)
		return (0);
	if (philo->number % 2 == 0)
	{
		pick_fork_up(&philo->lfork, philo);
		pick_fork_up(philo->rfork, philo);
	}
	else if (philo->number % 2 == 1)
	{
		pick_fork_up(philo->rfork, philo);
		pick_fork_up(&philo->lfork, philo);
	}
	eat(philo, philo->pkg);
	pthread_mutex_unlock(&philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	go_sleep(philo, philo->pkg);
	think(philo, philo->pkg);
	return (NULL);
}

void	*ft_loop(t_philo *philo)
{
	if (philo->pkg->someone_died)
		return (0);
	while (!dead(philo))
	{
		routine(philo);
		// if (number of times philo ate == times philo must eat)
			// note it somewhere... if all philos have now eaten enough, the simulation ends here
	}
	if (philo->pkg->someone_died)
		return (0);
	return (NULL);
}

void	eat(t_philo	*philo, t_data *pkg)
{
	if (dead(philo))
	{
		philo_says("died.\n", philo);
		pkg->someone_died = 1;
		return ;
	}
	philo_says("is eating\n", philo);
	philo->last_meal = return_time();
	ft_usleep(pkg->t2eat);
}

void	go_sleep(t_philo *philo, t_data *pkg)
{
	if (dead(philo))
	{
		philo_says("died.\n", philo);
		pkg->someone_died = 1;
		return ;
	}
	philo_says("is sleeping\n", philo);
	ft_usleep(pkg->t2sleep);
}

void	think(t_philo *philo, t_data *pkg)
{
	if (dead(philo))
	{
		philo_says("died.\n", philo);
		pkg->someone_died = 1;
		return ;
	}
	philo_says("is thinking\n", philo);
}

void	pick_fork_up(pthread_mutex_t *m, t_philo *philo)
{
	if (dead(philo))
	{
		philo_says("died.\n", philo);
		philo->pkg->someone_died = 1;
		return ;
	}
	pthread_mutex_lock(m);
	philo_says("has taken a fork\n", philo);
}
