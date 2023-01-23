/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:37:11 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/23 16:48:46 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosopher.h"

int	philo_eat(t_philo *philo)
{
	int	starved;
	int	supp_time;

	starved = 0;
	supp_time = philo->prog->tte - philo->prog->ttd;
	print_state(philo, "is eating 🍝");
	pthread_mutex_unlock(&philo->prog->printer);
	pthread_mutex_unlock(&philo->prog->waiter);
	if (supp_time > 0)
	{
		ft_sleep(philo->prog->ttd);
		if (philo_starved(philo))
			starved = 1;
		else
			ft_sleep(supp_time);
	}
	else
		ft_sleep(philo->prog->tte);
	philo->last_time_eat = get_time();
	philo->nb_eat++;
	philo->just_eat = 1;
	return (starved + philo_starved(philo));
}

int	philo_take_fork(t_philo *philo)
{
	print_state(philo, "has taken fork 🍴");
	return (philo_starved(philo));
}

int	philo_sleep(t_philo *philo)
{
	int	supp_time;

	supp_time = philo->prog->tts - philo->prog->ttd;
	pthread_mutex_lock(&philo->prog->printer);
	print_state(philo, "is sleeping 🛌");
	pthread_mutex_unlock(&philo->prog->printer);
	if (supp_time > 0)
	{
		ft_sleep(philo->prog->ttd);
		if (philo_starved(philo))
			return (1);
		ft_sleep(supp_time);
	}
	else
		ft_sleep(philo->prog->tts);
	return (philo_starved(philo));
}

int	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->printer);
	print_state(philo, "is thinking ");
	pthread_mutex_unlock(&philo->prog->printer);
	return (philo_starved(philo));
}
