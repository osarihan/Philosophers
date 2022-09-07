/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:17:49 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/07 14:46:03 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(int ac, char **av, t_data *data)
{
	data->n_philo = av[1];
	data->die_time = av[2];
	data->eat_time = av[3];
	data->sleep_time = av[4];
	if (data->n_philo < 1 || data->die_time < 1
		|| data->eat_time < 1 || data->sleep_time < 1)
		return(0);
	if (ac == 6)
	{
		data->notepme = av[5];
	}
	else
		data->notepme = -1;
	data->dead = 0;
	data->eat_ok = 0;
	pthread_mutex_init(&data->msg, NULL);
	pthread_mutex_init(&data->isdead, NULL);
	return(1);
}

int	init_forks(t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_philo)
	{
		if (!pthread_mutex_init(&data->forks[i], NULL))
			return(0);
		i++;
	}
	return(1);
}

int	init_philos(t_data *data)
{
	int i;
	
	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		return (0);
	while (i < data->n_philo - 1)
	{
		data->philo[i].id = i + 1;
		data->philo[i].l_fork = i + 1;
		data->philo[i].r_fork = i;
		data->philo[i].dead = 0;
		data->philo[i].notepme = data->notepme;
		data->philo[i].data = data;
		i++;
	}
	data->philo[i].id = i + 1;
	data->philo[i].l_fork = 0;
	data->philo[i].r_fork = i;
	data->philo[i].dead = 0;
	data->philo[i].notepme = data->notepme;
	data->philo[i].data = data;
	return (1);
}
