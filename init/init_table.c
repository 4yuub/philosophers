/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:55:20 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/13 10:56:11 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "colors.h"

void	init_table(t_table **table, bool *error, char **av, t_list **garbage)
{
	(*table) = malloc(sizeof(t_table));
	add_garbge((*table), garbage);
	(*table)->nbr_of_philos = ft_atoi(av[1], error);
	(*table)->nbr_of_full_philos = 0;
	(*table)->die = ft_atoi(av[2], error);
	if ((*table)->nbr_of_philos > 3)
		(*table)->die += 10;
	(*table)->eat = ft_atoi(av[3], error);
	(*table)->sleep = ft_atoi(av[4], error);
	(*table)->start_time = get_time();
	if (av[5])
		(*table)->full = ft_atoi(av[5], error);
	else
		(*table)->full = 0;
	if (*error)
	{
		clear(garbage);
		printf("%sArgs error\n%s", RED, WHITE);
	}
}
