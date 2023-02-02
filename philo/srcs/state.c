/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:37:11 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/26 12:08:46 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/philosopher.h"

int	philo_eat(t_philo *philo)
{
	int	starved;

	philo->nb_eat++;
	philo->just_eat = 1;
	print_state(philo, "is eating 🍝");
	starved = action_time(philo, philo->prog->ttd);
	philo->last_time_eat = get_time();
	return (starved + philo_starved(philo));
}

int	action_time(t_philo *philo, long long duration)
{
	long long int	supp_time;
	int				starved;

	supp_time = (philo->last_time_eat - get_time()) + duration;
	starved = 0;
	if (supp_time > (long long)philo->prog->ttd)
	{
		ft_sleep(philo->prog, philo->prog->ttd);
		starved = philo_starved(philo);
		if (starved == 0)
			ft_sleep(philo->prog, supp_time - philo->prog->ttd);
	}
	else
	{
		if (duration > philo->prog->ttd)
		{
			ft_sleep(philo->prog, philo->prog->ttd);
			starved = philo_starved(philo);
			if (starved == 0)
				ft_sleep(philo->prog, duration - philo->prog->ttd);
		}
		else
			ft_sleep(philo->prog, duration);
	}
	return (starved + philo_starved(philo));
}

int	philo_take_fork(t_philo *philo)
{
	print_state(philo, "has taken fork 🍴");
	return (philo_starved(philo));
}

int	philo_sleep(t_philo *philo)
{
	int starved;

	print_state(philo, "is sleeping 🛌");
	starved = action_time(philo, philo->prog->tts);
	return (starved + philo_starved(philo));
}

int	philo_think(t_philo *philo)
{
	print_state(philo, "is thinking 🤔");
	return (philo_starved(philo));
}
