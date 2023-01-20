/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:00:09 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/20 17:37:54 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/philosopher.h"

void	free_all(t_program *t_prog)
{
	int	n;

	n = 0;
	pthread_mutex_destroy(&t_prog->waiter);
	pthread_mutex_destroy(&t_prog->printer);
	while (n < t_prog->nb_philo)
	{
		pthread_mutex_destroy(&t_prog->forks[n]);
		n++;
	}
	free(t_prog->philos);
	free(t_prog->forks);
}

int	main(int argc, char **argv)
{
	t_program	t_prog;

	if (!parse_arg(&t_prog, argc, argv))
	{
		printf("Erreur: Argument non valide\n");
		return (1);
	}
	init_forks(&t_prog);
	init_philos(&t_prog);
	free_all(&t_prog);
	return (0);
}
