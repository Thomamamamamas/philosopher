/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:01:20 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/10 15:17:16 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			ttd;
	int			tte;
	int			tts;
	int			limit_eat;
	int			nb_must_eat;
	int			nb_eat;
}				t_philo;

typedef struct s_program
{
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				limit_eat;
	int				nb_must_eat;
	pthread_t		*threads;
	pthread_mutex_t	forks;
}					t_program;

//parsing
int		parse_arg(t_program *t_prog, int argc, char **argv);
int		check_good_parsing_value(t_program *t_prog, char **argv);
void	init_philos(t_program *t_prog);
//utils
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
//philo
void	*lifestyle(void *p);


#endif
