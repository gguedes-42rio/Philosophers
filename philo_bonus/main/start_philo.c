/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:27:24 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 15:31:20 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philo(t_philo *philo, int *philosophers, char **argv)
{
	*philosophers = atol(argv[0]);
	if (*philosophers < 1)
		return (1);
	philo->time_to_die = atol(argv[1]);
	if (philo->time_to_die < 1)
		return (1);
	philo->time_to_eat = atol(argv[2]);
	if (philo->time_to_eat < 1)
		return (1);
	philo->time_to_sleep = atol(argv[3]);
	if (philo->time_to_sleep < 1)
		return (1);
	if (argv[4])
	{
		philo->must_eat = atol(argv[4]);
		if (philo->must_eat < 1)
			return (1);
	}
	else
		philo->must_eat = -1;
	philo->id = 1;
	philo->eaten = 0;
	philo->death = 0;
	return (0);
}
