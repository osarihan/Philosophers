/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:56:01 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/29 14:46:07 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				s;
	unsigned int	res;

	i = 0;
	s = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * s);
}

void	go_sleep(int num)
{
	long long int	time;

	time = get_time();
	while (num > get_time() - time)
		usleep(50);
}

void	msg(int time, char *str, t_philo *p)
{	
	sem_wait(p->data->speak);
	if (death_lock(p) != 1)
		exit(1);
	time = time - p->data->s_time;
	if (time < 0)
		time = 0;
	if (p->dead == 0 && death_lock(p) == 1)
		printf("timestamp_in_ms:%d, philo_no_%d, %s\n", time, p->id, str);
	sem_post(p->data->speak);
}

long long int	get_time(void)
{
	struct timeval	i;

	gettimeofday (&i, NULL);
	return ((i.tv_sec * 1000) + (i.tv_usec / 1000));
}

void	*is_dead2(void *ptr)
{
	t_philo	*ph;

	ph = (t_philo *)ptr;
	while (1)
	{
		sem_wait(ph->data->meal_check);
		if ((get_time() - ph->leat) > ph->data->die_time && ph->leat != 0)
		{
			msg(get_time(), "died", ph);
			sem_wait(ph->data->death);
			ph->data->someone_died = 1;
			sem_post(ph->data->death);
			exit(1);
		}
		sem_post(ph->data->meal_check);
		if (ph->data->someone_died)
			break ;
		sem_wait(ph->data->death);
		if (ph->eat_count == ph->data->notepme && ph->data->notepme != -1)
			ph->data->all_eat++;
		if (ph->data->all_eat == ph->data->n_philo)
			ph->data->someone_died = 1;
		sem_post(ph->data->death);
	}
	return (NULL);
}
