/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:43:21 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/13 16:01:27 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/philosopher.h"

void	*life(void *tmp_philo)
{
	t_philo		*philo;
	int			dead;

	philo = (t_philo *)tmp_philo;
	dead = 0;
	while (check_diner_continu(philo->prog))
	{
		if (dead == 0 && (check_is_valid_eater(philo) || philo->just_sleep))
		{
			dead = philo_think(philo);
			if (dead == 0)
				dead = eat_procedure(philo);
		}
		else if (dead == 0 && !philo->just_sleep)
			dead = philo_sleep(philo);
		else
			return (philo_funeral(philo));
	}
	return (NULL);
}

int	eat_procedure(t_philo *philo)
{
	int	res;

	res = grab_forks(philo);
	res = philo_eat(philo);
	philo->r_fork->used = 0;
	philo->l_fork->used = 0;
	pthread_mutex_unlock(&philo->l_fork->mutex);
	pthread_mutex_unlock(&philo->r_fork->mutex);
	return (res);
}

int	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork->mutex);
	philo_take_fork(philo);
	pthread_mutex_lock(&philo->r_fork->mutex);
	philo_take_fork(philo);
	return (philo_starved(philo));
}

int	philo_starved(t_philo *philo)
{
	if (get_time() - philo->last_time_eat >= (long long)philo->prog->ttd)
		return (1);
	return (0);
}

void	*philo_funeral(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_printer);
	if (philo->prog->is_dead)
	{
		pthread_mutex_unlock(&philo->prog->death_printer);
		return (NULL);
	}
	print_state(philo, "died");
	pthread_mutex_lock(&philo->prog->checker);
	philo->prog->is_dead = 1;
	pthread_mutex_unlock(&philo->prog->checker);
	pthread_mutex_unlock(&philo->prog->death_printer);
	return (NULL);
}
