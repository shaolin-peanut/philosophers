#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
// REMOVE AFTER TESTING
#include <stdio.h>

typedef	struct s_philo t_philo;

struct s_philo
{
	pthread_t		id;
	int				number;
	pthread_mutex_t	lfork;
	pthread_mutex_t	rfork;
	struct s_data	*pkg;
};

typedef	struct s_data	
{
	int	pc;
	int	t2die;
	int	t2eat;
	int	t2sleep;
	int	eatXtimes;
	pthread_mutex_t print_lock;
	t_philo	**philos;
}	t_data;

// philosophers.c
// loop.c
void	*ft_loop(t_philo *philo);
void	eat(t_philo	*philo, t_data *pkg);
void	pick_fork_up(pthread_mutex_t	*m);
void	put_fork_down(pthread_mutex_t	*m);
void	go_sleep(t_philo *philo, t_data *pkg);
void	think(t_philo *philo, t_data *pkg);
// parsing.c
t_data	*parsing(int argc, char	**argv);
void	create_philos(char	**argv, t_data	*pkg);
int		create_fork(pthread_mutex_t *lock);
// init.c
t_data	*init_pkg(t_data *pkg);
t_philo	**init_philos(t_philo	**philos, int nbr, t_data	*pkg);
void	fill_pkg(t_data *pkg, char **argv);
// utils.c
void	errormsg(char	*msg, t_data	*pkg);
void	free_all(t_data	*pkg);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
// utils2.c
int		return_time(void);
int		death_of_a_philosopher(void);
void	ft_putstr(char	*str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
// utils3.c
void	print_current_time(void);

#endif
