/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 05:10:46 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/06 19:49:01 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*do_routin(t_philo *philo)
{
	while (true)
	{
		pthread_mutex_lock(&philo->fork);
		printf("%ld %d has taken a fork\n", get_time2(philo), philo->number);
		pthread_mutex_lock(&philo->previous->fork);
		printf("%ld %d has taken a fork\n", get_time2(philo), philo->number);
		printf("%ld %d is eating\n", get_time2(philo), philo->number);
		usleep(philo->table->eat * 1e3);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->previous->fork);
		printf("%ld %d is sleeping\n", get_time2(philo), philo->number);
		usleep(philo->table->sleep * 1e3);
		printf("%ld %d is thinking\n", get_time2(philo), philo->number);
	}
	return (NULL);
}
