/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:21:35 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/08 03:00:55 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "colors.h"

void	init_table_bonus(t_table_b **table, int ac, char **av, t_list **garbage)
{
	bool	error;

	error = false;
	(*table) = malloc(sizeof(t_table));
	add_garbge((*table), garbage);
	(*table)->nbr_of_philos = ft_atoi(av[1], &error);
	(*table)->die = ft_atoi(av[2], &error);
	(*table)->eat = ft_atoi(av[3], &error);
	(*table)->sleep = ft_atoi(av[4], &error);
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

void	do_routin_bonus(t_philo_b *philo)
{
	printf("hello proccess %d\n", philo->number);
}

void	start_philos(t_table_b *table, t_list **garbage)
{
	t_philo_b	*philo;
	int			i;

	i = -1;
	sem_init(&table->forks, 1, table->nbr_of_philos);
	while (++i < table->nbr_of_philos)
	{
		philo = malloc(sizeof(t_philo_b));
		philo->last_eat = get_time();
		philo->nbr_of_eats = 0;
		philo->number = i + 1;
		philo->table = table;
		if (fork() == 0)
		{
			do_routin_bonus(philo);
			exit(0);
		}
	}
}
