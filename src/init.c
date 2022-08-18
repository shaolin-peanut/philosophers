/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:37:20 by sbars             #+#    #+#             */
/*   Updated: 2022/08/18 15:54:06 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	init_pkg(t_data	*pkg)
{
	pkg = (t_data	*) malloc(sizeof(pkg));
	if (!pkg)
		errormsg("malloc error\n");
	pkg->t2die = 0;
	pkg->t2eat = 0;
	pkg->t2sleep = 0;
	pkg->eatXtimes = 0;
	pkg->phil = 0;
}

void	fill_pkg(t_data *pkg, char	**argv)
{
	pkg->t2die = ft_atoi(argv[1]);
	pkg->t2eat = ft_atoi(argv[2]);
	pkg->t2sleep = ft_atoi(argv[3]);
}
