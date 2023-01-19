#include "../headers/philosopher.h"

int	philo_eat(t_philo *philo)
{
	print_state(philo, "sleeping 🛌");
	ft_sleep(philo->prog->tts);
	philo->last_time_eat = get_time();
	philo->nb_eat++;
	return (philo_starved(philo));
}

int	philo_sleep(t_philo *philo)
{
	print_state(philo, "eating 🍝");
	ft_sleep(philo->prog->tte);
	return (philo_starved(philo));
}
