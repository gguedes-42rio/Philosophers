/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:42:58 by gguedes           #+#    #+#             */
/*   Updated: 2023/03/17 02:07:24 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->mutex_stop);
	if (philo->global->stop)
	{
		pthread_mutex_unlock(&philo->global->mutex_stop);
		return (1);
	}
	if (philo->death <= get_ms())
	{
		philo->global->stop = 1;
		pthread_mutex_lock(&philo->global->mutex_print);
		printf("%li %i is dead\n", get_ms() - philo->start, philo->id);
		pthread_mutex_unlock(&philo->global->mutex_print);
		pthread_mutex_unlock(&philo->global->mutex_stop);
		return (1);
	}
	pthread_mutex_unlock(&philo->global->mutex_stop);
	return (0);
}
