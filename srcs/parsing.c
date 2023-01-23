/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:00:07 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/23 11:26:15 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/philosopher.h"

int	parse_arg(t_program *t_prog, int argc, char **argv)
{
	if (argc >= 5)
	{
		if (argc <= 6)
		{
			t_prog->nb_philo = ft_atoi(argv[1]);
			t_prog->ttd = ft_atoi(argv[2]);
			t_prog->tte = ft_atoi(argv[3]);
			t_prog->tts = ft_atoi(argv[4]);
			if (argc == 6)
			{
				t_prog->limit_eat = 1;
				t_prog->nb_must_eat = ft_atoi(argv[5]);
			}
			else
				t_prog->limit_eat = 0;
			return (check_good_parsing_value(t_prog, argv));
		}
	}
	return (0);
}

int	check_good_parsing_value(t_program *t_prog, char **argv)
{
	if (t_prog->nb_philo == 0 && ft_strcmp(argv[1], "0") != 0)
		return (0);
	if (t_prog->ttd == 0 && ft_strcmp(argv[2], "0") != 0)
		return (0);
	if (t_prog->tte == 0 && ft_strcmp(argv[3], "0") != 0)
		return (0);
	if (t_prog->tts == 0 && ft_strcmp(argv[4], "0") != 0)
		return (0);
	if (t_prog->limit_eat == 1)
	{
		if (t_prog->nb_must_eat == 0 && ft_strcmp(argv[5], "0") != 0)
			return (0);
	}
	return (1);
}

void	init_forks(t_program *t_prog)
{
	int	n;

	n = 0;
	t_prog->forks = malloc(sizeof(pthread_mutex_t) * t_prog->nb_philo);
	pthread_mutex_init(&t_prog->printer, NULL);
	pthread_mutex_init(&t_prog->waiter, NULL);
	while (n < t_prog->nb_philo)
	{
		pthread_mutex_init(&t_prog->forks[n], NULL);
		n++;
	}
}

void	init_philos(t_program *t_prog)
{
	int		n;

	n = 0;
	t_prog->start_time = get_time();
	t_prog->order = 0;
	t_prog->philos = (t_philo *)malloc(sizeof(t_philo) * t_prog->nb_philo);
	while (n < t_prog->nb_philo)
	{
		t_prog->philos[n].id = n + 1;
		t_prog->philos[n].nb_eat = 0;
		t_prog->philos[n].prog = t_prog;
		t_prog->philos[n].last_time_eat = t_prog->start_time;
		pthread_create(&t_prog->philos[n].thread, NULL, life, &t_prog->philos[n]);
		n++;
	}
	n = 0;
	while (n < t_prog->nb_philo)
	{
		pthread_join(t_prog->philos[n].thread, NULL);
		n++;
	}
}
