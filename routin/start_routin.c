/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 04:21:51 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/06 05:41:32 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_routin(t_table *table, t_philo *first)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = first;
	(void) table;
	while (!i++ || philo != first)
	{
		pthread_create(&philo->th, NULL, (void *)(void *)do_routin, philo);
		philo = philo->next;
	}
}

void	wait_threads(t_philo *first)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = first;
	while (!i++ || philo != first)
	{
		pthread_join(philo->th, NULL);
		pthread_mutex_destroy(&philo->fork);
		philo = philo->next;
	}
}
