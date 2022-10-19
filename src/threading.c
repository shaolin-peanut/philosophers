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
//		pthread_detach(pkg->philos[i]->id);
    }
    i = -1;
    while (++i < pkg->pc && pkg->philos[i] != 0)
    {
      if (pkg->someone_died)
      pthread_detach(pkg->philos[i]->id);
    }
    return (0);
}

void  finish_program(t_data *pkg)
{
  int   i;

  i = -1;
  (void) pkg;
  // while (++i < pkg->pc)
  // {
    // pthread_mutex_destroy(&pkg->philos[i]->lfork);
    // pthread_exit(pkg->philos[i]);
  // } 
  exit(EXIT_FAILURE);
}

int death_monitor(t_data *pkg)
{
  while (1)
  {
    if (pkg->someone_died == 1)
      finish_program(pkg);
    ft_usleep(10);
  }
  return (0);
}
