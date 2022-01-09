/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:21:35 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/09 03:06:27 by akarafi          ###   ########.fr       */
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

void	start_philos(t_table_b *table, t_list **garbage)
{
	t_philo_b	*philo;
	int			i;

	sem_unlink("forks");
	sem_unlink("print");
	table->forks = sem_open("forks", O_CREAT, 0644, table->nbr_of_philos);
	table->print = sem_open("print", O_CREAT, 0644, 1);
	i = -1;
	while (++i < table->nbr_of_philos)
	{
		philo = malloc(sizeof(t_philo_b));
		add_garbge(philo, garbage);
		philo->last_eat = get_time();
		philo->nbr_of_eats = 0;
		philo->number = i + 1;
		philo->table = table;
		if (fork() == 0)
		{
			do_routin_bonus(philo);
			exit(0);
		}
		usleep(100);
	}
	while (i--)
		waitpid(-1, NULL, 0);
	sem_close(table->forks);
}
