/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:46:31 by sbars             #+#    #+#             */
/*   Updated: 2022/08/26 16:17:20 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

t_data	*parsing(int	c, char	**av)
{
	t_data	*pkg;

	pkg = NULL;
	if (c < 5 || c > 6)
	{
		ft_putstr("Too little or too many args");
		exit(EXIT_FAILURE);
	}
	pkg = init_pkg(pkg);
	fill_pkg(pkg, av);
	if (c == 6)
	{
		pkg->eatXtimes = ft_atoi(av[c - 1]);
		if (pkg->eatXtimes < 1)
			errormsg("Incorrect Input\n", pkg);
	}
	// TESTING
//	printf("%d\n", pkg->pc);
//	printf("%d\n", pkg->t2die);
//	printf("%d\n", pkg->t2eat);
//	printf("%d\n", pkg->t2sleep);
//	printf("%d\n", pkg->eatXtimes);
	return (pkg);
}


void	fill_pkg(t_data *pkg, char **argv)
{
	t_philo	**philos;
	int		ret;

	philos = NULL;
	ret = 0;
	pkg->pc = ft_atoi(argv[1]);
	pkg->t2die = ft_atoi(argv[2]);
	pkg->t2eat = ft_atoi(argv[3]);
	pkg->t2sleep = ft_atoi(argv[4]);
	if (pkg->pc < 1 || pkg->t2die < 1 || pkg->t2eat < 1 || pkg->t2sleep < 1)
		errormsg("Incorrect Input\n", pkg);
	ret = pthread_mutex_init(&pkg->print_lock, NULL);
	if (ret != 0)
		errormsg("mutex init error", pkg);
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

void	create_philos(t_data	*pkg)
{
	int i;

	i = -1;
	// init philos number, pkg and left fork
	while (++i < pkg->pc && pkg->philos[i] != 0)
	{

		pkg->philos[i]->number = i + 1;
		pkg->philos[i]->pkg = pkg;
		// What about the left fork of the first philosopher?
		if (create_fork(&pkg->philos[i]->lfork) != 0)
				errormsg("fork creation error\n", pkg);
	}
	i = -1;
	while (++i < pkg->pc && pkg->philos[i] != 0)
	{
		if (i > 0)
			pkg->philos[i]->rfork = &pkg->philos[i - 1]->lfork;
		else
			pkg->philos[0]->rfork = &pkg->philos[pkg->pc - 1]->lfork;
	}
}
