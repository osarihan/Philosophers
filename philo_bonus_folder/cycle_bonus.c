/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:00:41 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/21 12:37:56 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eat(t_philo *p)
{	
	p->f_init = get_time();
	if (p->data->someone_died > 0 || p->data->all_eat == p->data->n_philo)
		exit(1);
	sem_wait(p->data->forks);
	msg(get_time(), "has taken a fork", p);
	sem_wait(p->data->forks);
	msg(get_time(), "has taken a fork", p);
	sem_wait(p->data->meal_check);
	if (p->data->someone_died > 0 || p->data->all_eat == p->data->n_philo)
		exit(1);
	msg(get_time(), "is eating", p);
	p->leat = get_time();
	p->eat_count++;
	sem_post(p->data->meal_check);
	go_sleep(p->data->eat_time);
	sem_post(p->data->forks);
	sem_post(p->data->forks);
}

void	philo_think(t_philo *p)
{
	p->f_init = get_time();
	if (p->dead != 0 || p->data->someone_died == 1 || \
		p->data->all_eat == p->data->n_philo)
		exit(1);
	msg(get_time(), "Is thinking", p);
}

void	philo_sleep(t_philo *p)
{
	p->f_init = get_time();
	if (p->dead != 0 || p->data->someone_died == 1 || \
		p->data->all_eat == p->data->n_philo)
		exit(1);
	msg(get_time(), "is sleeping", p);
	go_sleep(p->data->sleep_time);
}

void	cycle(void *p)
{
	t_philo	*ph;

	ph = (t_philo *)p;
	ph->data->s_time = get_time();
	pthread_create(&(ph->death_check), NULL, is_dead2, p);
	if (ph->id % 2 == 0)
		go_sleep(ph->data->eat_time);
	while (ph->data->someone_died == 0)
	{
		philo_eat(ph);
		philo_sleep(ph);
		philo_think(ph);
	}
	pthread_join(ph->death_check, NULL);
	if (ph->data->someone_died != 0)
		exit(1);
	exit(0);
}

int	start_threads(t_data *data)
{
	int		i;
	t_philo	*phi;

	i = -1;
	phi = data->philos;
	data->s_time = get_time();
	while (++i < data->n_philo)
	{
		phi[i].proc_id = fork();
		if (phi[i].proc_id < 0)
			return (1);
		if (phi[i].proc_id == 0)
			cycle(&(phi[i]));
		usleep(100);
	}
	kill_the_child(data);
	return (0);
}
