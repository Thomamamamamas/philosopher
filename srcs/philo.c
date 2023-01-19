/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:43:21 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/18 17:25:18 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/philosopher.h"

void	*life(void *tmp_philo)
{
	t_philo		*philo;
	int			dead;

	philo = (t_philo *)tmp_philo;
	while (!philo->prog->is_dead && philo->nb_eat < philo->prog->nb_must_eat)
	{
		if (philo->prog->order == philo->id % 2)
		{
			dead = grab_forks(philo);
			dead = philo_eat(philo);
		}
		else
		{
			dead = philo_sleep(philo);
		}
		if (dead == 1)
			philo_funeral(philo);
	}
	return (NULL);
}

void	grab_forks(t_philo *philo)
{
	int	n;

	n = philo->id;
	pthread_mutex_lock(&philo->prog->forks[n]);
}

int		philo_starved(t_philo *philo)
{
	long long	actual_time;

	actual_time = get_time();
	if (philo->last_time_eat - actual_time >= philo->prog->ttd)
		return (1);
	return (0);
}

void	philo_funeral(t_philo *philo)
{
	print_state(philo, "dead 💀");
	philo->prog->is_dead = 1;
}
