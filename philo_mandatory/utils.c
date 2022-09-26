/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:56:01 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/26 12:59:19 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	go_sleep(int num, t_philo *ph)
{
	long long int	time;

	time = get_time();
	while (num > get_time() - time)
	{
		if (!death_lock(ph))
			break;
		usleep(50);
	}
}

void	msg(int time, char *str, t_philo *p)
{	
	pthread_mutex_lock(&p->data->speak);
	if (time < 0)
		time = 0;
	printf("timestamp_in_ms:%d, philo_no_%d, %s\n", time, p->id, str);
	pthread_mutex_unlock(&p->data->speak);
}

long long int	get_time(void)
{
	struct timeval	i;

	gettimeofday (&i, NULL);
	return ((i.tv_sec * 1000) + (i.tv_usec / 1000));
}

int	is_dead(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->death);
	while (i < data->n_philo)
	{
		if (data->philos[i].eat_count == data->notepme)
			set(data, 1, 0);
		if ((data->philos[i].leat != 0 && data->die_time
				< (int)(get_time() - data->philos[i].leat)) || \
					(data->philos[i].f_init != 0 && data->die_time \
						< (int)(get_time() - data->philos[i].f_init)))
		{
			set(data, 2, i);
			pthread_mutex_unlock(&data->death);
			return (1);
		}
		//usleep(50);
		//printf("%lld\n", get_time() - data->philos[i].leat);
		i++;
	}
	pthread_mutex_unlock(&data->death);
	return (0);
}	
