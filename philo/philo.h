#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int id;
	int l_fork;
	int r_fork;
	int dead;
	int notepme;
	t_data *data;
} t_philo;

typedef struct s_data
{
	int	n_philo;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	notepme;
	int dead;
	int eat_ok;
	t_philo *philo;
	pthread_mutex_t *forks;
	pthread_mutex_t isdead;
	pthread_mutex_t msg;
} t_data;

///////////////////libft_utils/////////////////////////////
int		ft_atoi(const char *str);
///////////////////philo_utils/////////////////////////////
int		init_args(int ac, char **av, t_data *data);
int		init_forks(t_data *data);
int		init_philos(t_data *data);
///////////////////action_utils////////////////////////////
int		start_action(t_data *data);
void	*start_cycle(void *philo);
#endif