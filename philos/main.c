/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarihan <osarihan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:40:35 by osarihan          #+#    #+#             */
/*   Updated: 2022/09/16 17:53:58 by osarihan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char  **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		init_args(ac, av, &data);
		if (!(check_args(&data, 1)))
			return(0);
		start_threads(&data);
		//write(1, "Her sey düzgun gitti!\n", 24);
		return(0);
	}
	else
		write(2, "Error\nArgumanlar hatali!\n", 26);
	return (0);
}
