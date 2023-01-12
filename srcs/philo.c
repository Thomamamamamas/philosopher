
#include "../headers/philosopher.h"

void	*lifestyle(void *tmp_p)
{
	t_philo	*p;

	p = (t_philo *)tmp_p;
	printf("pute\n");
	free(tmp_p);
	pthread_join(p->thread, NULL);
	pthread_exit(NULL);
}
