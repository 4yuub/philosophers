/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 04:27:58 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/07 04:52:48 by akarafi          ###   ########.fr       */
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
		philo = philo->next;
	}
}
