/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:40:35 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/27 17:38:06 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (!check_init_args(ac, av))
		{
			write(2, "Error\nArgumanlar hatali!\n", 26);
			return (0);
		}
		init_args(ac, av, &data);
		if (!(check_args(&data, 1)))
			return (0);
		start_threads (&data);
		ft_free (&data);
		return (0);
	}
	else
		write(2, "Error\nArgumanlar hatali!\n", 26);
	return (0);
}

void	one_philo(t_philo *p)
{
	pthread_mutex_lock(&p->data->forks[p->l_fork]);
	msg(get_time(), "has taken a fork", p);
	go_sleep(p->data->die_time);
	msg(get_time(), "died", p);
	pthread_mutex_unlock(&p->data->forks[p->l_fork]);
	return ;
}
