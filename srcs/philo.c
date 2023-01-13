
#include "../headers/philosopher.h"

void	*lifestyle(void *tmp_p)
{
	t_philo	*p;

	p = (t_philo *)tmp_p;
	ft_sleep(100);
	print_state(p, "is sleeping");
	return (NULL);
}
