#include "philo.h"

int processing(t_data *pkg)
{
    int i;

    i = -1;
    while (++i < pkg->pc && pkg->philos[i] != 0)
    {
		 // if (i % 2 == 0)
			  // ft_usleep(pkg->t2eat / 10);
      pthread_create(&pkg->philos[i]->id, 0, (void *) ft_loop, pkg->philos[i]);
		  pthread_create(&pkg->philos[i]->death_id, NULL, (void *) death_monitor, pkg->philos[i]);
//		pthread_detach(pkg->philos[i]->id);
    }
    i = -1;
    while (++i < pkg->pc && pkg->philos[i] != 0)
    {
      pthread_detach(pkg->philos[i]->death_id);
      pthread_join(pkg->philos[i]->id, NULL);
    }
    return (0);
}

void  die(t_philo *philo)
{
  int   i;

  i = -1;
  philo_says("died.\n", philo);
  while (++i < philo->pkg->pc)
  {
    pthread_mutex_destroy(&philo->pkg->philos[i]->lfork);
    pthread_exit(philo->pkg->philos[i]);
  } 
  exit(EXIT_FAILURE);
}

int death_monitor(t_philo *philo)
{
  while (1)
  {
    if (dead(philo))
      die(philo);
    ft_usleep(10);
  }
  return (0);
}
