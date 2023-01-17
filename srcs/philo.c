
#include "../headers/philosopher.h"

void	*lifestyle(void *tmp_philo)
{
	t_philo		*philo;

	philo = (t_philo *)tmp_philo;
	printf("____________\n");
	printf("%d\n", philo->id);
	return (NULL);
}

void	philo_died(t_philo *philo)
{
	print_state(philo, "dead 💀");
	pthread_detach(philo->thread);
}
