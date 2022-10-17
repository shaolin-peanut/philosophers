#include "philo.h"

int processing(t_data *pkg)
{
    int i;

    i = -1;
    while (++i < pkg->pc && pkg->philos[i] != 0)
    {
		if (i % 2 == 0)
			ft_usleep(pkg->t2eat / 10);
		pthread_create(&pkg->philos[i]->id, 0, (void *) ft_loop, pkg->philos[i]);
		pthread_detach(pkg->philos[i]->id);
    }
    i = -1;
    while (++i < pkg->pc && pkg->philos[i] != 0)
    {
        pthread_join(pkg->philos[i]->id, NULL);
    }
    return (0);
}
