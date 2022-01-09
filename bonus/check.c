/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:07:09 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/09 17:17:02 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(t_philo_b *philo)
{
	while (1)
	{
		if (get_time() - philo->last_eat > philo->table->die)
		{
			sem_wait(philo->table->print);
			printf("%ld %d die\n", get_time3(philo), philo->number);
			exit(0);
		}
		usleep(500);
	}
}
