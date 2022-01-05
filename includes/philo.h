/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:35:47 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/05 04:46:47 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

// garbage collector:
typedef struct s_list
{
	void			*ptr;
	struct s_list	*next;
}	t_list;

void	clear(t_list **garbage);
void	add_garbge(void *ptr, t_list **garbage);

// philo:
typedef struct timeval	t_time;
typedef struct s_table
{
	int		sleep;
	int		eat;
	int		die;
	int		full;
	int		nbr_of_philos;
	t_time	time;
}		t_table;

typedef struct s_philo
{
	pthread_t		th;
	int				number;
	pthread_mutex_t	fork;
	struct s_philo	*next;
	struct s_philo	*previous;
}		t_philo;

// init:
void	init_table(t_table **table, int ac, char **av, t_list **garbage);
t_philo	*get_philos(t_table *table, t_list **garbage);

// common utils:
int		ft_atoi(const char *str, bool *error);

// do routin:
void	start_routin(t_table *table, t_philo *first);
void	wait_threads(t_philo *first);
#endif