/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:24:33 by sbars             #+#    #+#             */
/*   Updated: 2022/10/21 19:28:31 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	processing(t_data *pkg)
{
	int	i;

	i = -1;
	while (++i < pkg->pc && pkg->philos[i] != 0 && !pkg->someone_died)
	{
		if (i % 2 == 0)
			ft_usleep(pkg->t2eat / 10);
		pthread_create(&pkg->philos[i]->id, 0, (void *) ft_loop, pkg->philos[i]);
		pthread_create(&pkg->philos[i]->death_monitor, 0, (void *) death_monitor, pkg->philos[i]);
		pthread_detach(pkg->philos[i]->death_monitor);
	}
	i = -1;
	while (++i < pkg->pc && pkg->philos[i] != 0 && !pkg->someone_died)
	{
		// if (pkg->someone_died > 1)
		// 	free_all(pkg);
		pthread_join(pkg->philos[i]->id, NULL);
	}
	free_all(pkg);
	return (0);
}

int	death_monitor(t_philo *philo)
{
	(void) philo;
// {
//   while (!dead(philo))
//   {
//     ft_usleep(philo->pkg->t2die + 1);
//     if (dead(philo))
//       return (announce_death(philo));
//   }
	// while (!dead(philo))
	// {
	//   if (philo->pkg->someone_died == 1)
	//     finish_program(philo->pkg);
	//   ft_usleep(10);
	// }
	while (1)
	{
		check_aliveness_announce_and_exit(philo);
		ft_usleep(2);
	}
	return (0);
}

int	check_aliveness_announce_and_exit(t_philo *philo)
{
	if (philo->pkg->someone_died > 1)
	{
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
	// check_aliveness_announce_and_exit(philo);
	if (philo->pkg->pc == 1)
	{
		pick_fork_up(&philo->lfork, philo);
		ft_usleep(philo->pkg->t2die);
		announce_death(philo);
		pthread_exit(NULL);
	}
	if (philo->number % 2 == 0)
	{
		pick_fork_up(&philo->lfork, philo);
		pick_fork_up(philo->rfork, philo);
		// check_aliveness_announce_and_exit(philo);
	}
	else if (philo->number % 2 == 1)
	{
		pick_fork_up(philo->rfork, philo);
		pick_fork_up(&philo->lfork, philo);
		// check_aliveness_announce_and_exit(philo);
	}
	// check_aliveness_announce_and_exit(philo);
	eat(philo, philo->pkg);
	pthread_mutex_unlock(&philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	// check_aliveness_announce_and_exit(philo);
	go_sleep(philo, philo->pkg);
	// check_aliveness_announce_and_exit(philo);
	think(philo, philo->pkg);
	return (NULL);
}
