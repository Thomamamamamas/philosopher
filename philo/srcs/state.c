/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:37:11 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/09 16:19:23 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/philosopher.h"

int	philo_eat(t_philo *philo)
{
	long long	last;
	long long	ttl;

	philo->nb_eat++;
	philo->last_time_eat = get_time();
	last = philo->last_time_eat - get_time();
	ttl = philo->prog->ttd - last;
	print_state(philo, "is eating");
	return (action_time(philo, philo->prog->tte, ttl));
}

int	action_time(t_philo *philo, long long duration, long long ttl)
{
	if (ttl < duration)
	{
		ft_sleep(philo->prog, ttl);
		if (!philo_starved(philo))
			ft_sleep(philo->prog, duration - ttl);
	}
	else
		ft_sleep(philo->prog, duration);
	return (philo_starved(philo));
}

int	philo_take_fork(t_philo *philo)
{
	print_state(philo, "has taken fork");
	return (philo_starved(philo));
}

int	philo_sleep(t_philo *philo)
{
	int			starved;
	long long	last;
	long long	ttl;

	print_state(philo, "is sleeping");
	last = get_time() - philo->last_time_eat;
	ttl = philo->prog->ttd - last;
	starved = action_time(philo, philo->prog->tts, ttl);
	philo->just_sleep = 1;
	return (starved + philo_starved(philo));
}

int	philo_think(t_philo *philo)
{
	print_state(philo, "is thinking");
	return (philo_starved(philo));
}
