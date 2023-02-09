/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:37:41 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/09 12:51:26 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/philosopher.h"

int	check_is_valid_eater(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->prog->checker);
	res = 0;
	if (philo->prog->order == philo->id % 2 && philo->just_eat == 0)
			res = 1;
	pthread_mutex_unlock(&philo->prog->checker);
	return (res);
}

int	check_all_eat(t_program *prog)
{
	int	n;

	n = 0;
	if (prog->limit_eat == 0)
		return (0);
	while (n < prog->nb_philo)
	{
		if (prog->philos[n].nb_eat < prog->nb_must_eat)
			return (0);
		n++;
	}
	return (1);
}

int	check_change_order(t_program *prog)
{
	int	n;

	n = 0;
	while (n < prog->nb_philo)
	{
		if (prog->order == prog->philos[n].id % 2 && prog->philos[n].just_eat == 0)
			return (prog->order);
		n++;
	}
	n = 0;
	while (n < prog->nb_philo)
	{
		prog->philos[n].just_eat = 0;
		n++;
	}
	if (prog->order == 1)
		return (0);
	else
		return (1);
}

int	check_diner_continu(t_program *prog)
{
	int	res;

	res = 1;
	pthread_mutex_lock(&prog->checker);
	if (prog->is_dead || prog->eat_all)
		res = 0;
	pthread_mutex_unlock(&prog->checker);
	return (res);
}
