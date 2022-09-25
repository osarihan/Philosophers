/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:12:51 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/25 14:41:16 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_data *data)
{
	int	i;

	i = 0;
	//pthread_mutex_unlock(&data->speak);
	//pthread_mutex_destroy (&data->speak);
	while (i < data->n_philo)
	{
		//pthread_mutex_destroy (&data->forks[i]);
		pthread_detach (data->threads[i]);
		i++;
	}
	return (1);
}

void	set(t_data *data)
{
	data->all_eat++;
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
	else if (a == 1)
	{
		p->f_init = get_time();
		return ;
	}
}