/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:46:31 by sbars             #+#    #+#             */
/*   Updated: 2022/08/22 15:54:32 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
// remove after testing!!
#include <stdio.h>

void	parsing(int	c, char	**av)
{
	t_data	*pkg;

	pkg = NULL;
	if (c < 5 || c > 6)
		errormsg("Too little or too many args", pkg);
	pkg = init_pkg(pkg);
	fill_pkg(pkg, av);
	if (c == 6)
		pkg->eatXtimes = ft_atoi(av[c - 1]);
	printf("%d\n", pkg->pc);
	printf("%d\n", pkg->t2die);
	printf("%d\n", pkg->t2eat);
	printf("%d\n", pkg->t2sleep);
	printf("%d\n", pkg->eatXtimes);
	int	i = -1;
	while (++i < pkg->pc)
		printf("philos[%d]: %d\n", i, pkg->philos[i]->number);
}


void	fill_pkg(t_data *pkg, char	**argv)
{
	t_philo	**philos;

	philos = NULL;
	pkg->pc = ft_atoi(argv[1]);
	pkg->t2die = ft_atoi(argv[2]);
	pkg->t2eat = ft_atoi(argv[3]);
	pkg->t2sleep = ft_atoi(argv[4]);
	pkg->philos = init_philos(philos, pkg->pc, pkg);
	if (!pkg->philos)
		errormsg("philos mem allocation error\n", pkg);
	create_philos(pkg->philos, argv, pkg);
}

void	create_philos(t_philo	**philos, char	**argv, t_data	*pkg)
{
	int i;

	i = -1;
	(void) argv;
	(void) pkg;
	while (++i < pkg->pc && philos[i] != 0)
	{
	//	pthread_create(&philos[i]->id, 0, (void *) ft_loop, pkg);
		philos[i]->number = i;
		// create_fork(philos[i]->lfork)
	}
}
