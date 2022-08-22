#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef	struct s_philo t_philo;

struct s_philo
{
	pthread_t	id;
	int			number;
	int			lfork;
	int			rfork;
};

typedef	struct s_data	
{
	int	pc;
	int	t2die;
	int	t2eat;
	int	t2sleep;
	int	eatXtimes;
	t_philo	**philos;
}	t_data;

// philosophers.c
// loop.c
void	*ft_loop(void	*id);
// parsing.c
void	parsing(int argc, char	**argv);
void	create_philos(t_philo	**philos, char	**argv, t_data	*pkg);
// init.c
t_data	*init_pkg(t_data *pkg);
t_philo	**init_philos(t_philo	**philos, int nbr, t_data	*pkg);
void	fill_pkg(t_data *pkg, char **argv);
// utils.c
void	errormsg(char	*msg, t_data	*pkg);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif
