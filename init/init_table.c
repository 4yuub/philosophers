/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:55:20 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/07 05:23:54 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "colors.h"

void	init_table(t_table **table, int ac, char **av, t_list **garbage)
{
	bool	error;

	error = false;
	(*table) = malloc(sizeof(t_table));
	add_garbge((*table), garbage);
	(*table)->nbr_of_philos = ft_atoi(av[1], &error);
	(*table)->nbr_of_full_philos = 0;
	(*table)->die = ft_atoi(av[2], &error);
	(*table)->eat = ft_atoi(av[3], &error);
	(*table)->sleep = ft_atoi(av[4], &error);
	(*table)->start_time = get_time();
	if (ac == 6)
		(*table)->full = ft_atoi(av[5], &error);
	else
		(*table)->full = 0;
	if (error)
	{
		clear(garbage);
		printf("%sArgs error\n", RED);
		exit(0);
	}
}
