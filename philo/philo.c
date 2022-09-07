/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:16:48 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/07 14:49:47 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av)
{
	t_data data;
	
	if (ac < 5 || ac > 6)
		return (0);
	if (!init_args(ac, av, &data) || !init_forks(&data) || !init_philos(&data))
		return(0);
	if (!start_action(&data))
		return(0);
}
