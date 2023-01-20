/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:37:11 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/20 17:37:55 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosopher.h"

int	philo_eat(t_philo *philo)
{
	print_state(philo, "is eating 🍝");
	pthread_mutex_unlock(&philo->prog->printer);
	pthread_mutex_unlock(&philo->prog->waiter);
	ft_sleep(philo->prog->tts);
	philo->last_time_eat = get_time();
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	philo->nb_eat++;
	return (philo_starved(philo));
}

int	philo_take_fork(t_philo *philo)
{
	print_state(philo, "has taken fork 🍴");
	return (philo_starved(philo));
}

int	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->printer);
	print_state(philo, "is sleeping 🛌");
	pthread_mutex_unlock(&philo->prog->printer);
	ft_sleep(philo->prog->tte);
	return (philo_starved(philo));
}

int	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->printer);
	print_state(philo, "is thinking ");
	pthread_mutex_unlock(&philo->prog->printer);
	return (philo_starved(philo));
}
