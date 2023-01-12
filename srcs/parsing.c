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
	t_philo	*p;

	n = 0;
	t_prog->threads = (pthread_t*)malloc(sizeof(pthread_t) * t_prog->nb_philo);
	while (n < t_prog->nb_philo)
	{
		/*p.ttd = t_prog->ttd;
		p.tte = t_prog->tte;
		p.tts = t_prog->tts;
		p.limit_eat = t_prog->limit_eat;
		p.nb_must_eat = t_prog->nb_must_eat;
		p.nb_eat = 0;*/
		p = malloc(sizeof(t_philo));
		(*p).id = pthread_create(&p->thread, NULL, lifestyle, (void *) p);
		n++;
	}
}
