/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:46:31 by sbars             #+#    #+#             */
/*   Updated: 2022/08/24 16:40:10 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

t_data	*parsing(int	c, char	**av)
{
	t_data	*pkg;

	pkg = NULL;
	if (c < 5 || c > 6)
		errormsg("Too little or too many args", pkg);
	pkg = init_pkg(pkg);
	fill_pkg(pkg, av);
	if (c == 6)
		pkg->eatXtimes = ft_atoi(av[c - 1]);
	// TESTING
//	printf("%d\n", pkg->pc);
//	printf("%d\n", pkg->t2die);
//	printf("%d\n", pkg->t2eat);
//	printf("%d\n", pkg->t2sleep);
//	printf("%d\n", pkg->eatXtimes);
	return (pkg);
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
}

int	create_fork(pthread_mutex_t	*lock)
{
	int	ret;

	ret = 0;
	ret = pthread_mutex_init(lock, NULL);
	return (ret);
}

void	create_philos(char	**argv, t_data	*pkg)
{
	int i;
	t_philo	**philos;

	i = -1;
	(void) argv;
	philos = pkg->philos;
	while (++i < pkg->pc && philos[i] != 0)
	{
		philos[i]->number = i + 1;
		if (i > 0)
			philos[i]->rfork = philos[i - 1]->lfork;
		if (create_fork(&philos[i]->lfork) != 0)
				errormsg("fork creation error\n", pkg);
		pthread_create(&philos[i]->id, 0, (void *) ft_loop, philos[i]);
		pthread_detach(philos[i]->id);
		usleep(1000);
	}
	i = -1;
}
