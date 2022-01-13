/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 04:27:58 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/13 10:50:46 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death_and_full(t_philo *philo)
{
	while (true)
	{
		if (get_time() - philo->last_eat >= philo->table->die)
		{
			pthread_mutex_lock(&philo->table->print);
			printf("%ld %d die\n", get_time2(philo), philo->number);
			return ;
		}
		if (philo->table->full)
		{
			if (philo->table->nbr_of_full_philos >= philo->table->nbr_of_philos)
			{
				pthread_mutex_lock(&philo->table->print);
				return ;
			}
			if (philo->nbr_of_eats >= philo->table->full && !philo->is_full)
			{
				philo->is_full = true;
				philo->table->nbr_of_full_philos++;
			}
		}
		philo = philo->next;
	}
}
