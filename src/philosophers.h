#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>

typedef	struct s_philo t_philo;

struct s_philo
{
	int	id;
	int	lfork;
	int	rfork;
};

typedef	struct s_data	
{
	int	t2die;
	int	t2eat;
	int	t2sleep;
	int	eatXtimes;
	t_philo	*table;
}	t_data;

#endif
