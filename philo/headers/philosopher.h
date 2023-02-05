/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:01:20 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/26 12:08:50 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_program;

typedef struct s_philo
{
	pthread_t			thread;
	int					is_dead;
	int					id;
	long long			start_time;
	int					nb_eat;
	int					just_eat;
	long long			last_time_eat;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	struct s_program	*prog;
}						t_philo;

typedef struct s_program
{
	int				is_dead;
	int				eat_all;
	int				order;
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				limit_eat;
	int				nb_must_eat;
	long long		start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printer;
	pthread_mutex_t	death_printer;
	pthread_mutex_t	checker;
}					t_program;

void		free_all(t_program *prog);
//init
int			parse_arg(t_program *t_prog, int argc, char **argv);
int			check_good_parsing_value(t_program *t_prog, char **argv);
void		init_forks(t_program *forks);
void		init_philos(t_program *t_prog);
void		exit_philo_lifestyle(t_program *t_prog);
//utils
long long	get_time(void);
void		ft_sleep(t_program *philo, int time);
void		print_state(t_philo *philo, char *str);
int			ft_atoi(const char *str);
int			ft_strcmp(char *s1, char *s2);
//philo
void		*life(void *tmp_prog);
int			eat_procedure(t_philo *philo);
int			grab_forks(t_philo *philo);
int			philo_starved(t_philo *philo);
void		*philo_funeral(t_philo *philo);
//state
int			philo_eat(t_philo *philo);
int			action_time(t_philo *philo, long long duration, long long ttl);
int			philo_take_fork(t_philo *philo);
int			philo_sleep(t_philo *philo);
int			philo_think(t_philo *philo);
//check
int			check_is_valid_eater(t_philo *philo);
int			check_all_eat(t_program *t_prog);
int			check_change_order(t_program *t_prog);

#endif
