/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:00:41 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/27 17:40:34 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *p)
{
	if (!death_lock(p))
		return ;
	pthread_mutex_lock(&p->data->forks[p->l_fork]);
	pthread_mutex_lock(&p->data->forks[p->r_fork]);
	if (!death_lock(p))
		return ;
	msg(get_time(), "has taken a fork", p);
	msg(get_time(), "has taken a fork", p);
	pthread_mutex_lock(&p->data->death);
	set2(p, 2);
	pthread_mutex_unlock(&p->data->death);
	if (!death_lock(p))
		return ;
	msg (get_time(), "is eating", p);
	go_sleep(p->data->eat_time);
	pthread_mutex_unlock(&p->data->forks[p->l_fork]);
	pthread_mutex_unlock(&p->data->forks[p->r_fork]);
	return ;
}

void	philo_think(t_philo *p)
{
	if (!death_lock(p))
		return ;
	msg(get_time(), "is thinking", p);
}

void	philo_sleep(t_philo *p)
{
	if (!death_lock(p))
		return ;
	msg(get_time(), "is sleeping", p);
	go_sleep(p->data->sleep_time);
}

void	*cycle(void *p)
{
	t_philo	*ph;

	ph = (t_philo *)p;
	if (ph->id % 2 == 0)
		go_sleep(ph->data->eat_time);
	if (ph->data->n_philo == 1)
		one_philo(p);
	while (1)
	{
		if (ph->data->n_philo == 1)
			return (NULL);
		if (!death_lock(p))
			return (NULL);
		philo_eat(ph);
		if (!death_lock(p))
			return (NULL);
		philo_sleep(ph);
		if (!death_lock(p))
			return (NULL);
		philo_think(ph);
	}
	return (NULL);
}

int	start_threads(t_data *data)
{
	int	i;

	i = 0;
	data->threads = malloc(sizeof(pthread_t) * data->n_philo);
	while (i < data->n_philo)
	{
		data->philos[i].s_time = get_time();
		pthread_create(&data->threads[i], NULL, &cycle, &data->philos[i]);
		i++;
	}
	while (data->someone_died == 0)
	{
		is_dead(data);
		if (data->someone_died == 1 || \
			data->all_eat == data->n_philo || data->n_philo == 1)
			break ;
	}
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join (data->threads[i], NULL);
		i++;
	}
	return (1);
}
