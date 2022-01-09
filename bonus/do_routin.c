/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_routin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 02:59:55 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/09 03:12:26 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void __do_routin_b(t_philo_b *philo)
{
	sem_wait(philo->table->forks);
	sem_wait(philo->table->print);
	printf("%ld %d has taken a fork\n", get_time3(philo), philo->number);
	sem_post(philo->table->print);
	sem_wait(philo->table->forks);
	sem_wait(philo->table->print);
	printf("%ld %d has taken a fork\n", get_time3(philo), philo->number);
	printf("%ld %d is eating\n", get_time3(philo), philo->number);
	sem_post(philo->table->print);
	usleep(philo->table->eat * 1e3);
	philo->nbr_of_eats++;
	philo->last_eat = get_time();
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
	sem_wait(philo->table->print);
	printf("%ld %d is sleeping\n", get_time3(philo), philo->number);
	sem_post(philo->table->print);
	usleep(philo->table->sleep * 1e3);
	sem_wait(philo->table->print);
	printf("%ld %d is think\n", get_time3(philo), philo->number);
	sem_post(philo->table->print);
}

void	do_routin_bonus(t_philo_b *philo)
{
	while (1)
		__do_routin_b(philo);
}
