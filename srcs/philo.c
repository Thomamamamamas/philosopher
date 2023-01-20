/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:43:21 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/20 14:43:44 by tcasale          ###   ########.fr       */
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
			dead = philo_think(philo);
			dead = eat_procedure(philo);
		}
		else
			dead = philo_sleep(philo);
		if (dead == 1)
			philo_funeral(philo);
	}
	return (NULL);
}

int	eat_procedure(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->prog->waiter);
	pthread_mutex_lock(&philo->prog->printer);
	res = grab_forks(philo);
	res = philo_eat(philo);
	return (res);
}

int	grab_forks(t_philo *philo)
{
	int	tmp;

	if (philo->id == 0)
		philo->r_fork = &philo->prog->forks[philo->prog->nb_philo];
	else
		philo->r_fork = &philo->prog->forks[philo->id];
	if (philo->id == philo->prog->nb_philo)
		philo->l_fork = &philo->prog->forks[0];
	else
		philo->l_fork = &philo->prog->forks[philo->id- 1];
	pthread_mutex_lock(philo->l_fork);
	tmp = philo_take_fork(philo);
	pthread_mutex_lock(philo->r_fork);
	tmp = philo_take_fork(philo);
	return (philo_starved(philo));
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
