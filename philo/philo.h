/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:13:36 by osarihan          #+#    #+#             */
/*   Updated: 2022/08/30 17:42:44 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct t_philos{
	int number_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int	number_of_time_eat;
	pthread_t **threads;
}	t_philo;
//////////////////Libft//////////////////////////////
int		ft_atoi(const char *str);
//////////////////Philo_utils////////////////////////


#endif