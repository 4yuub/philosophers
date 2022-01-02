/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:35:47 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/02 23:52:21 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct timeval	t_time;
typedef struct s_table
{
	int		sleep;
	int		eat;
	int		die;
	int		full;
	t_time	time;
}		t_table;

typedef struct s_philo
{
	pthread_t		th;
	int				number;
	struct s_philo	next;
	struct s_philo	previous;
}		t_philo;
int		ft_atoi(const char *str);

#endif