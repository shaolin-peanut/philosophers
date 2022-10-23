/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:24:33 by sbars             #+#    #+#             */
/*   Updated: 2022/10/23 17:34:00 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	processing(t_data *pkg)
{
	int		i;
	t_philo	**ph;

	ph = pkg->philos;
	i = -1;
	while (++i < pkg->pc && pkg->philos[i] != 0 && !pkg->someone_died)
	{
		if (i % 2 == 0)
			ft_usleep(5);
		pthread_create(&ph[i]->id, 0, (void *) ft_loop, ph[i]);
		pthread_create(&ph[i]->death_monitor, 0, (void *) death_monitor, ph[i]);
		pthread_detach(ph[i]->death_monitor);
	}
	i = -1;
	while (++i < pkg->pc && pkg->philos[i] != 0 && !pkg->someone_died)
	{
		if (pkg->someone_died)
			free_all(pkg);
		pthread_join(pkg->philos[i]->id, NULL);
	}
	free_all(pkg);
	return (0);
}

int	death_monitor(t_philo *philo)
{
	(void) philo;
	while (1)
	{
		check_aliveness_announce_and_exit(philo);
		ft_usleep(3);
	}
	return (0);
}

int	check_aliveness_announce_and_exit(t_philo *philo)
{
	if (philo->pkg->someone_died || all_philos_ate_enough(philo->pkg) == 1)
	{
		pthread_mutex_unlock(&philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		pthread_exit(NULL);
	}
	else if (dead(philo))
	{
		announce_death(philo);
		philo->pkg->someone_died = 1;
		pthread_exit(NULL);
	}
	return (0);
}

void	*routine(t_philo *philo)
{
	if (philo->number == 1 || philo->number % 2 == 0)
	{
		pick_fork_up(&philo->lfork, philo);
		check_aliveness_announce_and_exit(philo);
		pick_fork_up(philo->rfork, philo);
	}
	else if (philo->number % 2 == 1)
	{
		pick_fork_up(philo->rfork, philo);
		check_aliveness_announce_and_exit(philo);
		pick_fork_up(&philo->lfork, philo);
	}
	check_aliveness_announce_and_exit(philo);
	eat(philo, philo->pkg);
	pthread_mutex_unlock(&philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	go_sleep(philo, philo->pkg);
	think(philo, philo->pkg);
	return (NULL);
}
