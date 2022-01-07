/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 04:21:51 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/07 05:18:37 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_routin(t_philo *first)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = first;
	while (!i++ || philo != first)
	{
		pthread_create(&philo->th, NULL, (void *)(void *)do_routin, philo);
		usleep(100);
		philo = philo->next;
	}
}

void	detach_threads(t_philo *first)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = first;
	while (!i++ || philo != first)
	{
		pthread_detach(philo->th);
		pthread_mutex_destroy(&philo->fork);
		philo = philo->next;
	}
}
