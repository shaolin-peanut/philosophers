/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:39:39 by sbars             #+#    #+#             */
/*   Updated: 2022/08/10 17:45:10 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
// remove after testing!!
#include <stdio.h>
#include <unistd.h>

int	x = 0;
pthread_mutex_t	mutex;

void	*routine()
{
	int	i;

	i = -1;
	while (++i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		x++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

/*void	*routine2()
{
	printf("value of x: %d\n", x);
	return (NULL);
}*/

int	philosophers(char	**argv)
{
	pthread_t	t1;
	pthread_t	t2;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL))
	{
		return 1;
	}
	if (pthread_create(&t2, NULL, &routine, NULL))
	{
		return 2;
	}
	if (pthread_join(t1, NULL))
	{
		return 3;
	}
	if (pthread_join(t2, NULL))
	{
		return 4;
	}
	printf("value of x: %d\n", x);
	return (0);
}

int	main(int argc, char	**argv)
{
	(void) argc;

	/*if (argc < 5)
		errormsg("enter more arguments", pkg);
	else if (argc > 6)
		errormsg("too much arguments", pkg);
	else if (argc == 5)*/
	return (philosophers(argv));
}
