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

void	*lifestyle(void *tmp_philo)
{
	t_philo		*philo;

	philo = (t_philo *)tmp_philo;
	return (NULL);
}

void	philo_died(t_philo *philo)
{
	print_state(philo, "dead 💀");
	pthread_detach(philo->thread);
}
