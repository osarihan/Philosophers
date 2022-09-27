/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:12:51 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/27 17:43:58 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_detach (data->threads[i]);
		i++;
	}
	return (1);
}

void	set(t_data *data, int i, int k)
{
	if (i == 1)
		data->all_eat++;
	if (i == 2)
	{
		msg (get_time(), "died", &data->philos[k]);
		data->philos->dead = 1;
		data->someone_died = 1;
	}
}

int	check_init_args(int argc, char **argv)
{
	int	i;
	int	j;	

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9'))
				j++;
			else if (j == 0 && argv[i][j] == '+' && argv[i][j + 1] > 32)
				j++;
			else
				return (0);
		}
		j = 0;
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

void	set2(t_philo *p, int a)
{
	if (a == 2)
	{
		p->eat_count++;
		p->leat = get_time();
		return ;
	}
}

int	death_lock(t_philo *p)
{
	pthread_mutex_lock(&p->data->death);
	if ((p->data->someone_died != 0) || \
		p->data->all_eat == p->data->n_philo)
	{
		pthread_mutex_unlock(&p->data->death);
		return (0);
	}
	pthread_mutex_unlock(&p->data->death);
	return (1);
}
