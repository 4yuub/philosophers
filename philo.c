/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:35:07 by akarafi           #+#    #+#             */
/*   Updated: 2021/12/31 18:00:58 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func(void *arg)
{
	printf("hello world!\n");
	sleep(1);
	printf("hello world again\n");
	return (arg);
}

int	main(int ac, char **av)
{
	pthread_t	th;
	pthread_t	th2;

	(void) av;
	(void) ac;
	pthread_create(&th, NULL, &func, NULL);
	pthread_create(&th2, NULL, &func, NULL);
	pthread_join(th, NULL);
	pthread_join(th2, NULL);
}
