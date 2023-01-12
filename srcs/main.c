/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:00:09 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/10 15:17:09 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/philosopher.h"

int	main(int argc, char **argv)
{
	t_program	t_prog;

	if (!parse_arg(&t_prog, argc, argv))
	{
		printf("Erreur: Argument non valide\n");
		return (1);
	}
	init_philos(&t_prog);
	return (0);
}
