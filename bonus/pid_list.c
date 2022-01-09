/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:25:28 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/09 19:48:45 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_pid(int id, t_pid **pids)
{
	t_pid	*pid;

	if (!pids)
		return ;
	pid = malloc(sizeof(t_pid));
	pid->id = id;
	pid->next = (*pids);
	(*pids) = pid;
}

void	clear_pids(t_pid **pid)
{
	t_pid	*tmp;

	while (*pid)
	{
		tmp = (*pid)->next;
		free(*pid);
		*pid = tmp;
	}
}
