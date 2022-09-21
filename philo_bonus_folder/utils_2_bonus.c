/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:12:51 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/21 12:24:31 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*int	ft_free(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy (&data->speak);
	while (i < data->n_philo)
	{
		pthread_mutex_destroy (&data->forks[i]);
		pthread_detach (data->threads[i]);
		i++;
	}
	return (1);
}*/

void	set(t_data *data, int i)
{
	data->all_eat++;
	data->philos[i].eat_count = 0;
}

int	check_init_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j] != '\0')
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9') || \
				(av[i][j] == '+' && av[i][j + 1] != ' '))
				j++;
			else
			{
				printf("argümanlar pozitif ve sayi olmalidir\n");
				return (0);
			}
		}
		j = 0;
		i++;
	}
	return (1);
}

void	kill_the_child(t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	while (i < data->n_philo)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < data->n_philo)
				kill(data->philos[i].proc_id, 15);
			break ;
		}
		i++;
	}
	sem_close(data->forks);
	sem_close(data->speak);
	sem_close(data->meal_check);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_mealcheck");
}
