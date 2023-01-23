/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:37:41 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/23 16:48:46 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/philosopher.h"

int	check_all_eat(t_program *t_prog)
{
	int	n;

	
	n = 0;
	if (t_prog->limit_eat == 0)
		return (0);
	while (n < t_prog->nb_philo)
	{
		if (t_prog->philos[n].nb_eat < t_prog->nb_must_eat)
			return (0);
		n++;
	}
	return (1);
}

int	check_change_order(t_program *t_prog)
{
	int	n;

	n = 0;
	while (n < t_prog->nb_philo)
	{
		if (t_prog->order == t_prog->philos[n].id % 2 && t_prog->philos[n].just_eat == 0)
			return (0);
		n++;
	}
	n = 0;
	while (n < t_prog->nb_philo)
	{
		t_prog->philos[n].just_eat = 0;
		n++;
	}
	if (t_prog->order == 1)
		t_prog->order = 0;
	else
		t_prog->order = 1;
	return (1);
}
