/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 06:04:50 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/09 02:46:11 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tp;
	long			time;

	gettimeofday(&tp, NULL);
	time = tp.tv_sec * 1e3 + tp.tv_usec / 1e3;
	return (time);
}

long	get_time2(t_philo *philo)
{
	return (get_time() - philo->table->start_time);
}

long	get_time3(t_philo_b *philo)
{
	return (get_time() - philo->table->start_time);
}
