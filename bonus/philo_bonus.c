/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:53:44 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/09 19:57:32 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "colors.h"

int	how_to_use(void)
{
	printf(
		"%show to use: %s\n\
%s./philo_bonus %s{nbr_of_philos} %s{time_to_die}\
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
	t_list		*garbage;
	t_table_b	*table;

	garbage = NULL;
	if (ac < 5 || ac > 6)
		return (how_to_use());
	init_table_bonus(&table, ac, av, &garbage);
	wait_philos(start_philos(table, &garbage));
	clear(&garbage);
}
