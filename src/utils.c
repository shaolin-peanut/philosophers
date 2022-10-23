/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:37:27 by sbars             #+#    #+#             */
/*   Updated: 2022/10/23 17:24:01 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_data	*pkg)
{
	int	i;

	i = -1;
	while (pkg->philos[++i] && i < pkg->pc)
	{
		pthread_mutex_unlock(&pkg->philos[i]->lfork);
		pthread_mutex_destroy(&pkg->philos[i]->lfork);
		pthread_exit(&pkg->philos[i]->id);
		free(pkg->philos[i]);
	}
}

void	free_all(t_data	*pkg)
{
	pkg->someone_died = 1;
	free_philos(pkg);
	pthread_mutex_unlock(&pkg->print_lock);
	pthread_mutex_destroy(&pkg->print_lock);
	if (pkg)
		free(pkg);
}

void	errormsg(char *msg, t_data	*pkg)
{
	int	i;

	i = -1;
	while (msg[++i])
		write(2, &msg[i], 1);
	//if (pkg->philos)
	//	free_philos(pkg);
	if (pkg)
		free(pkg);
	//pthread_mutex_unlock(&pkg->print_lock);
	//pthread_mutex_destroy(&pkg->print_lock);
	exit(EXIT_FAILURE);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	long int			result;
	int					i;
	long int			sign;

	result = 0;
	sign = 1;
	i = -1;
	while (str[++i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i++]))
		result = result * 10 + (str[i - 1] - 48);
	return (result * sign);
}
