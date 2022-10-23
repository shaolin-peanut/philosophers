/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:39:02 by sbars             #+#    #+#             */
/*   Updated: 2022/10/23 17:23:38 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_philos_ate_enough(t_data *pkg)
{
	int	i;

	i = -1;
	if (pkg->philos[0]->meal_count == 0 || pkg->meals_before_end == 0)
		return (0);
	while (pkg->philos[++i])
	{
		//printf("did all philos eat enough?\n- philos[%d]->mealcount:%d\n-meal before end:%d", i, pkg->philos[i]->meal_count, pkg->meals_before_end);
		if (pkg->philos[i]->meal_count < pkg->meals_before_end)
			return (0);
	}
	return (1);
}
