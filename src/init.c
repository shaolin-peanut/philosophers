/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:37:20 by sbars             #+#    #+#             */
/*   Updated: 2022/10/21 17:08:55 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_pkg(t_data	*pkg)
{
	pkg = (t_data *) malloc(sizeof(t_data));
	if (!pkg)
		errormsg("malloc error\n", pkg);
	pkg->pc = 0;
	pkg->t2die = 0;
	pkg->t2eat = 0;
	pkg->t2sleep = 0;
	pkg->meals_before_end = 0;
	pkg->start_time = return_time();
	pkg->someone_died = 0;
	pkg->philos = 0;
	return (pkg);
}

t_philo	**init_philos(t_philo	**philos, int nbr, t_data	*pkg)
{
	int	i;

	i = -1;
	philos = (t_philo **) malloc (sizeof(t_philo *) * nbr);
	if (!philos)
		errormsg("Philos malloc error!\n", pkg);
	while (++i < nbr)
	{
		philos[i] = (t_philo *) malloc(sizeof(t_philo));
		if (!philos[i])
			errormsg("philo malloc error", pkg);
	}
	i = -1;
	while (++i < nbr)
	{
		philos[i]->id = 0;
		philos[i]->number = 0;
		philos[i]->meal_count = 0;
		philos[i]->last_meal = return_time();
		philos[i]->pkg = 0;
	}
	return (philos);
}
