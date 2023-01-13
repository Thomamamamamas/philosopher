/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:00:07 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/10 15:17:11 by tcasale          ###   ########.fr       */
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

void	init_philos(t_program *t_prog)
{
	int		n;

	n = 0;
	t_prog->start_time = get_time();
	init_forks(t_prog);
	t_prog->philos = (t_philo *)malloc(sizeof(t_philo) * t_prog->nb_philo);
	while (n < t_prog->nb_philo)
	{
		t_prog->philos[n].id = n + 1;
		t_prog->philos[n].start_time = t_prog->start_time;
		t_prog->philos[n].ttd = t_prog->ttd;
		t_prog->philos[n].tte = t_prog->tte;
		t_prog->philos[n].tts = t_prog->tts;
		t_prog->philos[n].limit_eat = t_prog->limit_eat;
		t_prog->philos[n].nb_must_eat = t_prog->nb_must_eat;
		t_prog->philos[n].nb_eat = 0;
		pthread_create(&t_prog->philos[n].thread, NULL, lifestyle, &(t_prog->philos[n]));
		n++;
	}
	n = 0;
	while (n < t_prog->nb_philo)
	{
		pthread_join(t_prog->philos[n].thread, NULL);
		n++;
	}
}

void	init_forks(t_program *t_prog)
{
	int	n;

	n = 0;
	while (n < t_prog->nb_philo)
	{
		
		n++;
	}
}
