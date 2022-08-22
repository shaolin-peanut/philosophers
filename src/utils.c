/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:37:27 by sbars             #+#    #+#             */
/*   Updated: 2022/08/22 11:59:19 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	free_all(t_data	*pkg)
{
	if (pkg)
		free(pkg);
}

void	errormsg(char *msg, t_data	*pkg)
{
	int	i;

	i = -1;
	while (msg[++i])
		write(2, &msg[i], 1);
	free_all(pkg);
	exit(EXIT_FAILURE);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			result;
	int			i;
	int			sign;

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
