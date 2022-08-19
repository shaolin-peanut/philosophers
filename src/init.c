/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:37:20 by sbars             #+#    #+#             */
/*   Updated: 2022/08/19 16:46:06 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

t_data	*init_pkg(t_data	*pkg)
{
	pkg = (t_data	*) malloc(sizeof(t_data *));
	if (!pkg)
		errormsg("malloc error\n", pkg);
	pkg->pc = 0;
	pkg->t2die = 0;
	pkg->t2eat = 0;
	pkg->t2sleep = 0;
	pkg->eatXtimes = 0;
	pkg->phil = NULL;
	return (pkg);
}

void	fill_pkg(t_data *pkg, char	**argv)
{
	pkg->pc = ft_atoi(argv[1]);
	pkg->t2die = ft_atoi(argv[2]);
	pkg->t2eat = ft_atoi(argv[3]);
	pkg->t2sleep = ft_atoi(argv[4]);
}
