/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:56:01 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/20 16:32:43 by osarihan         ###   ########.fr       */
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
	if (p->dead != 0 || p->data->someone_died == 1 || \
		p->data->all_eat >= p->data->n_philo)
		exit(1) ;
	sem_wait(p->data->speak);
	if (p->dead != 0 || p->data->someone_died == 1 || \
		p->data->all_eat >= p->data->n_philo)
		exit(1) ;
	time = time - p->data->s_time;
	if (p->dead != 0 || p->data->someone_died == 1 || \
		p->data->all_eat >= p->data->n_philo)
		return ;
	if (p->dead == 0)
		printf("time:%d, philo_no_%d, %s\n", time, p->id, str);
	sem_post(p->data->speak);
}

long long int	get_time(void)
{
	struct timeval	i;

	gettimeofday (&i, NULL);
	return ((i.tv_sec * 1000) + (i.tv_usec / 1000));
}

/*int	is_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (data->philos[i].eat_count == data->notepme)
			set(data, i);
		if ((data->philos[i].leat != 0 && data->die_time
				< (int)(get_time() - data->philos[i].leat)) || \
					(data->philos[i].f_init != 0 && data->die_time \
						< (int)(get_time() - data->philos[i].f_init)))
		{
			if (data->philos->dead == 0)
			{
				msg (get_time(), "Died", &data->philos[i]);
				data->philos->dead = 1;
				data->someone_died = 1;
			}
			return (1);
		}
		i++;
	}
	return (0);
}*/

void	*is_dead2(void *ptr)
{
	t_philo	*ph;

	ph = (t_philo *)ptr;
	while (1)
	{
		sem_wait(ph->data->meal_check);
		if (((get_time() - ph->leat) > ph->data->die_time && ph->leat != 0) ||\
			 ((get_time() - ph->f_init) > ph->data->die_time && ph->f_init != 0))
		{
			msg(get_time(), "Died", ph);
				ph->data->someone_died = 1;
			exit(1);
		}
		sem_post(ph->data->meal_check);
		if (ph->data->someone_died)
			break ;
		usleep(1000);
		if (ph->eat_count >= ph->data->notepme && ph->data->notepme != -1)
			break ;
	}
	return (NULL);
}