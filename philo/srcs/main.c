/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:00:09 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/13 16:01:28 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/philosopher.h"

void	free_all(t_program *prog)
{
	int	n;

	n = 0;
	pthread_mutex_destroy(&prog->printer);
	pthread_mutex_destroy(&prog->death_printer);
	pthread_mutex_destroy(&prog->checker);
	while (n < prog->nb_philo)
	{
		pthread_mutex_destroy(&prog->forks[n].mutex);
		n++;
	}
	free(prog->philos);
	free(prog->forks);
}

int	main(int argc, char **argv)
{
	t_program	prog;

	if (!parse_arg(&prog, argc, argv))
		return (printf("Erreur: Argument non valide\n"));
	init_forks(&prog);
	init_philos(&prog);
	free_all(&prog);
	return (0);
}
