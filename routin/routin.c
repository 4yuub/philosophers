/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 05:10:46 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/07 04:44:35 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*do_routin(t_philo *philo)
{
	while (true)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&philo->table->print);
		printf("%ld %d has taken a fork\n", get_time2(philo), philo->number);
		pthread_mutex_unlock(&philo->table->print);
		pthread_mutex_lock(&philo->next->fork);
		pthread_mutex_lock(&philo->table->print);
		printf("%ld %d has taken a fork\n", get_time2(philo), philo->number);
		printf("%ld %d is eating\n", get_time2(philo), philo->number);
		pthread_mutex_unlock(&philo->table->print);
		usleep(philo->table->eat * 1e3);
		philo->last_eat = get_time();
		philo->nbr_of_eats++;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_lock(&philo->table->print);
		printf("%ld %d is sleeping\n", get_time2(philo), philo->number);
		pthread_mutex_unlock(&philo->table->print);
		usleep(philo->table->sleep * 1e3);
		pthread_mutex_lock(&philo->table->print);
		printf("%ld %d is thinking\n", get_time2(philo), philo->number);
		pthread_mutex_unlock(&philo->table->print);
	}
	return (NULL);
}
