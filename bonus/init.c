/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:21:35 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/11 21:10:41 by akarafi          ###   ########.fr       */
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
	(*table)->will_die = (
			(*table)->sleep + (*table)->eat > (*table)->die
			|| (*table)->nbr_of_philos == 1
			);
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

static void	init_semaphores(t_table_b *table)
{
	int	i;

	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("full");
	table->forks = sem_open("forks", O_CREAT, 0644, table->nbr_of_philos);
	table->nbr_of_full_philos = \
		sem_open("full", O_CREAT, 0644, table->nbr_of_philos);
	table->print = sem_open("print", O_CREAT, 0644, 1);
	i = -1;
	while (++i < table->nbr_of_philos)
		sem_wait(table->nbr_of_full_philos);
}

t_pid	*start_philos(t_table_b *table, t_list **garbage)
{
	t_philo_b	*philo;
	int			i;
	int			id;
	t_pid		*pids;

	i = -1;
	pids = NULL;
	init_semaphores(table);
	while (++i < table->nbr_of_philos)
	{
		philo = malloc(sizeof(t_philo_b));
		add_garbge(philo, garbage);
		philo->last_eat = get_time();
		philo->nbr_of_eats = 0;
		philo->number = i + 1;
		philo->table = table;
		id = fork();
		if (id == 0)
			do_routin_bonus(philo);
		add_pid(id, &pids);
		usleep(100);
	}
	return (pids);
}
