/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:12:51 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/19 12:14:02 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy (&data->forks[i]);
		pthread_detach (data->threads[i]);
		i++;
	}
	return (1);
}

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
			if ((av[i][j] >= '0' && av[i][j] <= '9'))
				j++;
			else
			{
				printf("argümanlar sayi olmalidir\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}