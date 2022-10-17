/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:39:39 by sbars             #+#    #+#             */
/*   Updated: 2022/08/24 16:40:18 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char	**argv)
{
	t_data	*pkg;

	pkg = NULL;
	pkg = parsing(argc, argv);
	create_philos(argv, pkg);
	processing(pkg);
	free_all(pkg);
	return (0);
}
