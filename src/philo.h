/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:57:53 by sbars             #+#    #+#             */
/*   Updated: 2022/10/23 16:29:25 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
// REMOVE AFTER TESTING
# include <stdio.h>

typedef struct s_philo	t_philo;

struct s_philo
{
	pthread_t		id;
	pthread_t		death_monitor;
	int				number;
	pthread_mutex_t	lfork;
	pthread_mutex_t	*rfork;
	int				meal_count;
	long int		last_meal;
	struct s_data	*pkg;
};

typedef struct s_data
{
	int				pc;
	long int		t2die;
	long int		t2eat;
	long int		t2sleep;
	int				meals_before_end;
	long int		start_time;
	int				someone_died;
	pthread_mutex_t	print_lock;
	t_philo			**philos;
}	t_data;

// philosophers.c
// loop.c
void		*ft_loop(t_philo *philo);
void		eat(t_philo	*philo, t_data *pkg);
void		pick_fork_up(pthread_mutex_t	*m, t_philo *philo);
void		put_fork_down(pthread_mutex_t	*m, t_philo *philo);
void		go_sleep(t_philo *philo, t_data *pkg);
void		think(t_philo *philo, t_data *pkg);
int			check_aliveness_announce_and_exit(t_philo *philo);
// parsing.c
t_data		*parsing(int argc, char	**argv);
void		create_philos(t_data	*pkg);
int			create_fork(pthread_mutex_t *lock);
// init.c
t_data		*init_pkg(t_data *pkg);
t_philo		**init_philos(t_philo	**philos, int nbr, t_data	*pkg);
void		fill_pkg(t_data *pkg, char **argv);
// utils.c
void		errormsg(char	*msg, t_data	*pkg);
void		free_all(t_data	*pkg);
long int	ft_atoi(const char *str);
int			ft_isdigit(int c);
// utils2.c
long int	return_time(void);
int			dead(t_philo *philo);
void		ft_putstr(char	*str);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
// utils3.c
void		print_current_time(void);
void		ft_usleep(long int time_in_ms);
void		ft_putnbr_long(long int n);
void		philo_says(char *str, t_philo *philo);
int			announce_death(t_philo *philo);
// utils4.c
int			all_philos_ate_enough(t_data *pkg);
// threading.c
int			processing(t_data *pkg);
void		*routine(t_philo *philo);
int			death_monitor(t_philo *philo);

#endif
