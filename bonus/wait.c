/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:52:28 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/11 21:11:15 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_philos(t_pid *pid, t_table_b *table)
{
	t_pid	*tmp;
	int		i;

	i = -1;
	while (++i < table->nbr_of_philos)
		sem_wait(table->nbr_of_full_philos);
	tmp = pid;
	while (pid)
	{
		kill(pid->id, SIGQUIT);
		pid = pid->next;
	}
	clear_pids(&tmp);
}
