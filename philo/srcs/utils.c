/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:46:19 by tcasale           #+#    #+#             */
/*   Updated: 2023/02/09 16:19:24 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/philosopher.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_sleep(t_program *prog, int time)
{
	long long	start_time;

	if (prog->is_dead)
		return ;
	start_time = get_time();
	while (get_time() - start_time < time)
		usleep(time / 10);
}

void	print_state(t_philo *philo, char *str)
{
	long long	time;

	pthread_mutex_lock(&philo->prog->printer);
	if (philo->prog->is_dead)
	{
		pthread_mutex_unlock(&philo->prog->printer);
		return ;
	}
	time = get_time() - philo->prog->start_time;
	printf("%6lld %3d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->prog->printer);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	negative;

	i = 0;
	result = 0;
	negative = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' \
	|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * negative);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while (s1[n] == s2[n] && s1[n] && s2[n])
		n++;
	return (s1[n] - s2[n]);
}
