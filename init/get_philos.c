/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:06:17 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/04 22:13:39 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	add_philo(int n, t_philo **philos)
{
	t_philo	*new_philo;

	new_philo = malloc(sizeof(t_philo));
	new_philo->number = n;
	if (philos == NULL)
	{
		new_philo->next = new_philo;
		new_philo->previous = new_philo;
		*philos = new_philo;
	}
	new_philo->next = *philos;
	new_philo->previous = (*philos)->previous;
	((*philos)->previous)->next = new_philo;
	(*philos)->previous = new_philo;
}

t_philo	*get_philos(t_table *table, t_list **garbage)
{
	t_philo	*first;
	int		i;

	i = 0;
	first = NULL;
	while (i < table->nbr_of_philos)
	{
		add_philo(i + 1, &first);
		i++;
	}
}
