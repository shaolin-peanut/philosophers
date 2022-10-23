/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:39:39 by sbars             #+#    #+#             */
/*   Updated: 2022/10/23 16:27:45 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	**argv)
{
	t_data	*pkg;

	pkg = NULL;
	pkg = parsing(argc, argv);
	create_philos(pkg);
	processing(pkg);
	if (pkg->someone_died == 1)
	{
		free_all(pkg);
		return (0);
	}
	return (0);
}
