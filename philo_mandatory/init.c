/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:40:18 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/25 16:08:41 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(t_data *data, int a)
{
	if (data->n_philo < 1 || data->die_time < 1 || \
		data->eat_time < 1 || data->sleep_time < 1)
	{
		write(2, "Error\nHatali arguman\n", 22);
		return (0);
	}
	if (a == 0)
		return (0);
	return (1);
}

void	init_args(int ac, char **av, t_data *data)
{
	data->n_philo = ft_atoi(av[1]);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->notepme = ft_atoi(av[5]);
	else
		data->notepme = -1;
	data->all_eat = 0;
	data->someone_died = 0;
	pthread_mutex_init(&data->speak, NULL);
	pthread_mutex_init(&data->death, NULL);
	forks(data);
	philos(data);
}

void	philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philos)
	{
		write(2, "Filozoflar için yer ayrılamadı!\n", 36);
		check_args(data, 0);
	}
	i = 0;
	while (i < data->n_philo - 1)
	{
		data->philos[i].eat_count = 0;
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].dead = 0;
		data->philos[i].l_fork = i + 1;
		data->philos[i].r_fork = i;
		i++;
	}
	data->philos[i].eat_count = 0;
	data->philos[i].data = data;
	data->philos[i].id = i + 1;
	data->philos[i].dead = 0;
	data->philos[i].l_fork = 0;
	data->philos[i].r_fork = i;
}

void	forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
	{
		write(2, "Catallar icin yer ayirilamadi!\n", 32);
		check_args(data, 0);
	}
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			write(2, "catal sorunu\n", 14);
			check_args(data, 0);
		}
		i++;
	}
}
