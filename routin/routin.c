/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 05:10:46 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/06 06:11:17 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*do_routin(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->previous->fork);
	//take fork
	//eating
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->previous->fork);
	//sleeping
	//thiking
	return (NULL);
}
