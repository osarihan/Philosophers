/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:48:44 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/07 16:32:07 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *start_cycle(void *philo)
{
	t_philo *philo;

	philo = (t_philo *)philo;
	while (1)
	{
		eat(philo);
		
	}
}

int	start_action(t_data *data)
{
	int i;
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t *) * data->n_philo);
	i = 0;
	while (i < data->n_philo)
	{
		pthread_create(&thread[i], NULL, &start_cycle, (void *)(&data->philo[i]));
		i++;
	}
}
