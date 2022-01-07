/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:35:07 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/07 05:16:01 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "colors.h"

int	how_to_use(void)
{
	printf(
		"%show to use: %s\n\
%s./philo %s{nbr_of_philos} %s{time_to_die}\
 %s{time_to_eat} %s{time_to_sleep}\
 %s{number_of_times_each_philosopher_must_eat}%s\n",
		BLUE,
		GREEN,
		WHITE,
		RED,
		RED,
		RED,
		RED,
		CYAN,
		WHITE
		);
	printf("\n\t\t\t\t\t%sRED%s is required %sCYAN%s is optional\n",
		RED, WHITE, CYAN, WHITE);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*garbage;
	t_philo	*first;
	t_table	*table;

	garbage = NULL;
	if (ac < 5 || ac > 6)
		return (how_to_use());
	init_table(&table, ac, av, &garbage);
	first = get_philos(table, &garbage);
	start_routin(first);
	check_death_and_full(first);
	detach_threads(first);
	clear(&garbage);
}
