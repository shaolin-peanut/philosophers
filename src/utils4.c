/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:39:02 by sbars             #+#    #+#             */
/*   Updated: 2022/10/21 19:02:57 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int all_philos_ate_enough(t_data *pkg)
{
    int i;

    i = -1;
    while (++i < pkg->pc && pkg->philos[i])
    {
        if (pkg->philos[i]->meal_count != pkg->meals_before_end)
            return (0);
    }
    return (1);
}