/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:32:53 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/07 17:52:51 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	t_sleep(int num)
{
	long long int	time;

	time = get_time();
	while (num > get_time() - time)
		usleep(50);
}

long long int	get_time(void)
{
	struct timeval	i;

	gettimeofday(&i, NULL);
	return ((i.tv_sec * 1000) + (i.tv_usec / 1000));
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->forks[philo->r_fork]));
	if (philo->data->dead == 1)
		return (0);
	write(1, "has taken a fork\n", 18);
	pthread_mutex_lock(&(philo->data->forks[philo->l_fork]));
	write(1, "has taken a fork\n", 18);
	philo->data->eat_time = get_time();
	if (philo->data->dead == 1)
		return (0);
	write(1, "eating\n", 8);
	t_sleep(philo->data->eat_time);
	philo->notepme--;
	pthread_mutex_unlock(&(philo->data->forks[philo->r_fork]));
	pthread_mutex_unlock(&(philo->data->forks[philo->l_fork]));
	return (1);
}