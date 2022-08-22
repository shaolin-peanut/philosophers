/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:37:20 by sbars             #+#    #+#             */
/*   Updated: 2022/08/22 15:51:49 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

t_data	*init_pkg(t_data	*pkg)
{
	pkg = (t_data	*) malloc(sizeof(t_data));
	if (!pkg)
		errormsg("malloc error\n", pkg);
	pkg->pc = 0;
	pkg->t2die = 0;
	pkg->t2eat = 0;
	pkg->t2sleep = 0;
	pkg->eatXtimes = 0;
	//pkg->philos = 0;
	return (pkg);
}

t_philo	**init_philos(t_philo	**philos, int nbr, t_data	*pkg)
{
	int	i;

	i = -1;
	philos = (t_philo **) malloc (sizeof(t_philo *) * nbr + 1);
	if (!philos)
		errormsg("Philos malloc error!\n", pkg);
	while (++i < nbr)
	{
		philos[i] = (t_philo	*) malloc(sizeof(t_philo));
		philos[i]->id = (pthread_t) malloc(sizeof(pthread_t));
		if (!philos[i])
			errormsg("indivvidual philo malloc error", pkg);
	}
	i = -1;
	while (++i < nbr)
	{
		pthread_create(&philos[i]->id, 0, (void *) ft_loop, pkg);
		pthread_detach(philos[i]->id);
		philos[i]->number = 0;
		philos[i]->lfork = 0;
		philos[i]->rfork = 0;
	}
	return (philos);
}

