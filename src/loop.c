/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:27:40 by sbars             #+#    #+#             */
/*   Updated: 2022/08/24 16:40:41 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	x = 0;

void	*ft_loop(t_philo *philo)
{
	//write(1, "hello\n", 6);
	//printf("ms right now%d\n", return_time());
//	while (!death_of_a_philosopher())
//	{
	pick_fork_up(&philo->lfork);
	eat(philo);
	put_fork_down(&philo->rfork);
		//sleep
		//think
//	}
	return (NULL);
}

void	eat(t_philo	*philo)
{	
	ft_putstr("Philosopher ");
	ft_putnbr_fd(philo->number, 1);
	ft_putstr(" is eating\n");
}

void	pick_fork_up(pthread_mutex_t *m)
{
	while (pthread_mutex_lock(m) != 0 && death_of_a_philosopher())
		;
}

void	put_fork_down(pthread_mutex_t *m)
{
	while (pthread_mutex_unlock(m) != 0 && death_of_a_philosopher())
		;
}
