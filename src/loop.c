/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:27:40 by sbars             #+#    #+#             */
/*   Updated: 2022/10/21 19:22:13 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_loop(t_philo *philo)
{
	check_aliveness_announce_and_exit(philo);
	while (!dead(philo))
	{
		check_aliveness_announce_and_exit(philo);
		routine(philo);
		//if (all_philos_ate_enough(philo->pkg))
		//{
		//	free_all(philo->pkg);
		//	pthread_exit(0);
		//}
	}
	if (philo->pkg->someone_died > 0)
		pthread_exit(NULL);
	return (NULL);
}

void	eat(t_philo	*philo, t_data *pkg)
{
	check_aliveness_announce_and_exit(philo);
	philo_says("is eating\n", philo);
	philo->last_meal = return_time();
	ft_usleep(pkg->t2eat);
}

void	go_sleep(t_philo *philo, t_data *pkg)
{
	check_aliveness_announce_and_exit(philo);
	philo_says("is sleeping\n", philo);
	ft_usleep(pkg->t2sleep);
}

void	think(t_philo *philo, t_data *pkg)
{
	check_aliveness_announce_and_exit(philo);
	if (!pkg->someone_died)
		philo_says("is thinking\n", philo);
}

void	pick_fork_up(pthread_mutex_t *m, t_philo *philo)
{
	check_aliveness_announce_and_exit(philo);
	if (!philo->pkg->someone_died)
	{
		pthread_mutex_lock(m);
		philo_says("has taken a fork\n", philo);
	}
}
