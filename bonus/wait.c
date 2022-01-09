/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:52:28 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/09 20:00:14 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_philos(t_pid *pid)
{
	t_pid	*tmp;

	waitpid(-1, NULL, 0);
	tmp = pid;
	while (pid)
	{
		kill(pid->id, SIGQUIT);
		pid = pid->next;
	}
	clear_pids(&tmp);
}
