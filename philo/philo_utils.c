/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:05:49 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/30 17:58:52 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(char **av, t_philo *philo)
{
	int a;
	int b;
	int c;
	int d;
	
	a = ft_atoi(av[0]);
	b = ft_atoi(av[1]);
	c = ft_atoi(av[2]);
	d = ft_atoi(av[3]);
	if (a < 1 || b < 1 || c < 1 || d < 1)
		return(0);
	philo->number_of_philos = a;
	philo->time_to_die = b;
	philo->time_to_sleep = c;
	philo->number_of_time_eat = d;
	return(1);
}
