/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:35:47 by akarafi           #+#    #+#             */
/*   Updated: 2022/01/11 17:00:36 by akarafi          ###   ########.fr       */
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

// bonus:
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>

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
	int				sleep;
	int				eat;
	int				die;
	int				full;
	bool				will_die;
	int				nbr_of_philos;
	int				nbr_of_full_philos;
	long			start_time;
	pthread_mutex_t	print;
}		t_table;

typedef struct s_philo
{
	pthread_t		th;
	int				number;
	pthread_mutex_t	fork;
	t_table			*table;
	long			last_eat;
	int				nbr_of_eats;
	bool			is_full;
	struct s_philo	*next;
	struct s_philo	*previous;
}		t_philo;

// init:
void	init_table(t_table **table, bool *error, char **av, t_list **garbage);
t_philo	*get_philos(t_table *table, t_list **garbage);

// common utils:
int		ft_atoi(const char *str, bool *error);
long	get_time(void);
long	get_time2(t_philo *philo);

// do routin:
void	start_routin(t_philo *first);
void	detach_threads(t_philo *first);
void	*do_routin(t_philo *philo);
void	check_death_and_full(t_philo *philo);

// bonus:

typedef struct s_table_b
{
	int		sleep;
	int		eat;
	int		die;
	int		full;
	int		nbr_of_philos;
	bool		will_die;
	long	start_time;
	sem_t	*forks;
	sem_t	*print;
	sem_t	*nbr_of_full_philos;
}		t_table_b;

typedef struct s_philo_b
{
	int			number;
	long		last_eat;
	t_table_b	*table;
	int			nbr_of_eats;
}		t_philo_b;

typedef struct s_pid
{
	int				id;
	struct s_pid	*next;
}	t_pid;

void	init_table_bonus(t_table_b **table, \
										int ac, char **av, t_list **garbage);
t_pid	*start_philos(t_table_b *table, t_list **garbage);
long	get_time3(t_philo_b *philo);
void	do_routin_bonus(t_philo_b *philo);
void	*check_death(t_philo_b *philo);

void	add_pid(int id, t_pid **pids);
void	clear_pids(t_pid **pid);
void	wait_philos(t_pid *pid, t_table_b *table);

#endif
