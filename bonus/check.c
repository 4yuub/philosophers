/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:07:09 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/13 10:50:26 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	__exit(t_table_b *table)
{
	int	i;

	i = -1;
	while (++i < table->nbr_of_philos)
		sem_post(table->nbr_of_full_philos);
}

void	*check_death(t_philo_b *philo)
{
	while (1)
	{
		if (get_time() - philo->last_eat > philo->table->die)
		{
			sem_wait(philo->table->print);
			printf("%ld %d die\n", get_time3(philo), philo->number);
			__exit(philo->table);
		}
		if (philo->table->full \
			&& philo->nbr_of_eats >= philo->table->full)
			sem_post(philo->table->nbr_of_full_philos);
		usleep(500);
	}
}
