
#include "../headers/philosopher.h"

void	*lifestyle(void *tmp_prog)
{
	t_program	*t_prog;
	//t_philo		*philo;

	t_prog = (t_program *)tmp_prog;
	//philo = &t_prog->philos[t_prog->actual_id];
	printf("____________\n");
	printf("%d\n", t_prog->actual_id);
	return (NULL);
}

void	philo_died(t_philo *philo)
{
	print_state(philo, "dead 💀");
	pthread_detach(philo->thread);
}
