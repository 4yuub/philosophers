/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:12:56 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/03 14:04:38 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear(t_list **garbage)
{
	t_list	*tmp;

	while (*garbage)
	{
		tmp = (*garbage)->next;
		free((*garbage)->ptr);
		free(*garbage);
		*garbage = tmp;
	}
}

void	add_garbge(void *ptr, t_list **garbage)
{
	t_list	*lst;

	if (!ptr || !garbage)
		return ;
	lst = malloc(sizeof(t_list));
	lst->ptr = ptr;
	lst->next = (*garbage);
	(*garbage) = lst;
}
