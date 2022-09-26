/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:40:18 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/22 15:56:36 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		i++;
	}
	data->philos[i].eat_count = 0;
	data->philos[i].data = data;
	data->philos[i].id = i + 1;
	data->philos[i].dead = 0;
}

void	forks(t_data *data)
{
	sem_unlink("/philo_forks");
	sem_unlink("/philo_speak");
	sem_unlink("/philo_mealcheck");
	data->forks = sem_open("/philo_forks", O_CREAT, S_IRWXU, data->n_philo);
	data->speak = sem_open("/philo_speak", O_CREAT, S_IRWXU, 1);
	data->meal_check = sem_open("/philo_mealcheck", O_CREAT, S_IRWXU, 1);
	return ;
}
