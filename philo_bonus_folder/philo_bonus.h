/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:49:57 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/22 17:07:56 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				dead;
	int				eat_count;
	struct s_data	*data;
	long long int	leat;
	long long int	f_init;
	pthread_t		death_check;
	pid_t			proc_id;
}	t_philo;

typedef struct s_data
{
	int				n_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				notepme;
	int				someone_died;
	long long int	s_time;
	int				all_eat;
	t_philo			*philos;
	sem_t			*forks;
	sem_t			*speak;
	pthread_mutex_t	death;
	sem_t			*meal_check;
}	t_data;

/////////////////////UTILS///////////////////////////////
void			go_sleep(int num);
long long int	get_time(void);
void			msg(int time, char *str, t_philo *p);
int				ft_atoi(const char *str);
////////////////////INIT_UTILS///////////////////////////
int				check_args(t_data *data, int a);
void			init_args(int ac, char **av, t_data *data);
void			forks(t_data *data);
void			philos(t_data *data);
///////////////////SIMULATION/////////////////////////////
void			philo_eat(t_philo *p);
int				start_threads(t_data *data);
int				is_dead(t_data *data);
int				check_args_int(char **av);
void			set(t_data *data, int i);
int	check_init_args(int argc, char **argv);
void			kill_the_child(t_data *data);
void			*is_dead2(void *ptr);
#endif
