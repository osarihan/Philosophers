#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_data data;

typedef struct s_philo
{
	int id;
	int l_fork;
	int r_fork;
	int dead;
	int	eat_count;
	struct s_data *data;
	long long int leat;
}	t_philo;

typedef struct s_data
{
	int	n_philo;
	int	die_time;
	int eat_time;
	int sleep_time;
	int notepme;
	int	someone_died;
	long long int	s_time;
	int	all_eat;
	t_philo *philos;
	pthread_mutex_t *forks;
	pthread_mutex_t death;
	pthread_mutex_t	speak;
	pthread_t		*threads;
}	t_data;

/////////////////////UTILS///////////////////////////////
void			go_sleep(int num);
long long int	get_time(void);
void			msg(int time, char *str, t_philo *p);
int				ft_atoi(const char *str);
////////////////////INIT_UTILS///////////////////////////
int 			check_args(t_data *data, int a);
void			init_args(int ac, char **av, t_data *data);
void			forks(t_data *data);
void			philos(t_data *data);
///////////////////SIMULATION/////////////////////////////
void			philo_eat(t_philo *p);
int				start_threads(t_data *data);
int 			is_dead(t_data *data);
int				check_args_int(char **av);
#endif