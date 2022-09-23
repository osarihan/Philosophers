/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:12:51 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/23 14:14:49 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set(t_data *data, int i)
{
	data->all_eat++;
	data->philos[i].eat_count = 0;
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
