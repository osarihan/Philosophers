/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:40:35 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/22 17:06:41 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		return (0);
	}
	else
		write(2, "Error\nArgumanlar hatali!\n", 26);
	return (0);
}
